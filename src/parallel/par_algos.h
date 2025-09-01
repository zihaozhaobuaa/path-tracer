#pragma once
#include "thread_pool.h"
#include <functional>
#include <vector>

namespace parallel {

// Very simple parallel for-each (skeleton)
template <class It, class Fn>
void for_each(ThreadPool& pool, It first, It last, Fn fn) {
  for (auto it = first; it != last; ++it) {
    pool.enqueue([=]() mutable { fn(*it); });
  }
}

} // namespace parallel
