#pragma once
#include <vector>
#include "../core/types.h"

namespace geom {
// Split polygon `aa` by polygon `po` segments (skeleton)
inline std::pair<std::vector<core::Point>, std::vector<core::Point>>
cut_by(const std::vector<core::Point>& aa, const std::vector<core::Point>& po) {
  (void)aa; (void)po;
  return {}; // TODO
}
} // namespace geom
