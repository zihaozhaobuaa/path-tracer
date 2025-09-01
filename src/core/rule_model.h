#pragma once
#include <string>
#include <vector>

namespace core {

// Minimal rule placeholders — customize to match contest
struct StartPos {
  std::string layer;
  int polygon_id{0};
};

struct ViaRule {
  std::string lower_layer; // adjacent lower
  std::string upper_layer; // adjacent upper
};

struct GateRule {
  std::string po_layer;
  std::string aa_layer;
};

struct Rules {
  std::vector<StartPos> starts;
  std::vector<ViaRule> vias;
  std::vector<GateRule> gates;
};

} // namespace core
