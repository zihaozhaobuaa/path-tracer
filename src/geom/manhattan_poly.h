#pragma once
#include <vector>
#include "../core/types.h"

namespace geom {
using core::Point;
using core::Box;

inline bool is_ccw(const std::vector<Point>& v) {
  long long a = 0;
  for (size_t i = 0; i < v.size(); ++i) {
    size_t j = (i + 1) % v.size();
    a += 1LL * v[i].x * v[j].y - 1LL * v[i].y * v[j].x;
  }
  return a > 0;
}

} // namespace geom
