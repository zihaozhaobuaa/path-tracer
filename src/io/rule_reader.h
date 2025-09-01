#pragma once
#include <string>
#include "../core/rule_model.h"

namespace io {
core::Rules read_rule(const std::string& path);
} // namespace io
