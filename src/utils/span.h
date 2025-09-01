#pragma once
#include <cstddef>

namespace utils {
template <class T>
struct span {
  T* data_;
  std::size_t size_;
  span(T* d, std::size_t n): data_(d), size_(n) {}
  T* begin() const { return data_; }
  T* end() const { return data_ + size_; }
  std::size_t size() const { return size_; }
};
} // namespace utils
