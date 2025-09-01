#pragma once
#include <string>
#include <vector>
#include "types.h"

namespace core {

struct Polygon {
  int id{0};
  std::vector<Point> v; // CCW
};

struct Layer {
  std::string name;
  std::vector<Polygon> polys;
};

struct Layout {
  std::vector<Layer> layers;
};

} // namespace core
