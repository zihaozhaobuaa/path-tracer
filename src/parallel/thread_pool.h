#pragma once
#include <functional>
#include <queue>
#include <thread>
#include <vector>
#include <atomic>

namespace parallel {

class ThreadPool {
  std::vector<std::thread> workers_;
  std::queue<std::function<void()>> tasks_;
  std::mutex m_;
  std::condition_variable cv_;
  std::atomic<bool> stop_{false};

  void worker() {
    while (true) {
      std::function<void()> task;
      {
        std::unique_lock<std::mutex> lk(m_);
        cv_.wait(lk, [&]{ return stop_ || !tasks_.empty(); });
        if (stop_ && tasks_.empty()) return;
        task = std::move(tasks_.front());
        tasks_.pop();
      }
      task();
    }
  }

public:
  explicit ThreadPool(int n) {
    if (n < 1) n = 1;
    workers_.reserve(n);
    for (int i = 0; i < n; ++i) workers_.emplace_back([this]{ worker(); });
  }
  ~ThreadPool() {
    {
      std::lock_guard<std::mutex> lk(m_);
      stop_ = true;
    }
    cv_.notify_all();
    for (auto& t : workers_) if (t.joinable()) t.join();
  }

  void enqueue(std::function<void()> f) {
    {
      std::lock_guard<std::mutex> lk(m_);
      tasks_.push(std::move(f));
    }
    cv_.notify_one();
  }
};

} // namespace parallel
