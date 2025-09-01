#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "../core/rule_model.h"

namespace trace {
struct ViaGraph {
  // map lower->set(upper), only adjacent per rules
  std::unordered_map<std::string, std::unordered_set<std::string>> adj;
};
} // namespace trace
