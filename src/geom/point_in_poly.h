#pragma once
#include "../core/types.h"
#include <vector>

namespace geom {
bool point_in_polygon_inclusive(const std::vector<core::Point>& v, core::Point p);
} // namespace geom
