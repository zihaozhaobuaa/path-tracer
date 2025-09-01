#pragma once
#include <string>
#include "../core/result_model.h"

namespace io {
void write_result(const std::string& path, const core::Result& r);
} // namespace io
