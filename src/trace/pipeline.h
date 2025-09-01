#pragma once
#include "../core/layout_model.h"
#include "../core/rule_model.h"
#include "../core/result_model.h"

namespace trace {

class Pipeline {
  int threads_;
public:
  explicit Pipeline(int threads=1): threads_(threads>0?threads:1) {}
  core::Result run(const core::Layout& layout, const core::Rules& rules);
};

} // namespace trace
