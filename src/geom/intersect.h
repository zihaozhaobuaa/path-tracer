#pragma once
#include "../core/types.h"
#include <vector>

namespace geom {

inline bool boxes_overlap(const core::Box& a, const core::Box& b) {
  return !(a.xmax < b.xmin || b.xmax < a.xmin || a.ymax < b.ymin || b.ymax < a.ymin);
}

// TODO: line/edge intersection, polygon overlap checks per contest.

} // namespace geom
