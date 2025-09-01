#include "point_in_poly.h"

namespace geom {

// Ray casting with edge-inclusive handling (skeleton)
bool point_in_polygon_inclusive(const std::vector<core::Point>& v, core::Point p) {
  bool inside = false;
  for (size_t i = 0, j = v.size() - 1; i < v.size(); j = i++) {
    auto xi = v[i].x, yi = v[i].y;
    auto xj = v[j].x, yj = v[j].y;
    bool intersect = ((yi > p.y) != (yj > p.y)) &&
                     (p.x < (xj - xi) * (p.y - yi) / double(yj - yi + (yj==yi)) + xi);
    if (intersect) inside = !inside;
  }
  return inside;
}

} // namespace geom
