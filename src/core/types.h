#pragma once
#include <cstdint>
#include <string>
#include <vector>

namespace core {
using i32 = std::int32_t;

struct Point {
  i32 x{0}, y{0};
};

struct Box {
  i32 xmin{0}, ymin{0}, xmax{0}, ymax{0};
};
} // namespace core
