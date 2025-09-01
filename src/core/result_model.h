#pragma once
#include <string>
#include <vector>
#include "types.h"

namespace core {

struct OutputPolygon {
  std::string layer;
  int id{0};
  std::vector<Point> v; // CCW
};

struct Result {
  std::vector<OutputPolygon> polys;
};

} // namespace core
