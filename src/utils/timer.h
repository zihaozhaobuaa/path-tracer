#pragma once
#include <chrono>
#include <string>
#include <cstdio>

namespace utils {
struct Timer {
  std::string name;
  std::chrono::high_resolution_clock::time_point t0;
  explicit Timer(std::string n): name(std::move(n)), t0(std::chrono::high_resolution_clock::now()) {}
  ~Timer() {
    using namespace std::chrono;
    auto t1 = high_resolution_clock::now();
    auto ms = duration_cast<milliseconds>(t1 - t0).count();
    std::fprintf(stderr, "[TIMER] %s: %lld ms\n", name.c_str(), (long long)ms);
  }
};
} // namespace utils
