#pragma once
#include <array>
#include <vector>

namespace utils {
template <class T, std::size_t N>
struct small_vec {
  std::array<T,N> buf{};
  std::vector<T> spill;
  std::size_t _size{0};

  void push_back(const T& x) {
    if (_size < N) buf[_size] = x;
    else spill.push_back(x);
    ++_size;
  }
  std::size_t size() const { return _size; }
};
} // namespace utils
