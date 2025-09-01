#include "result_writer.h"
#include <fstream>
#include <stdexcept>

namespace io {

void write_result(const std::string& path, const core::Result& r) {
  std::ofstream ofs(path);
  if (!ofs) throw std::runtime_error("Cannot open output file: " + path);

  // TODO: Replace with required output format for the contest.
  ofs << "# net-trace skeleton output\n";
  ofs << "# polygons: " << r.polys.size() << "\n";
  for (const auto& p : r.polys) {
    ofs << p.layer << " " << p.id << " " << p.v.size();
    for (const auto& pt : p.v) ofs << " " << pt.x << " " << pt.y;
    ofs << "\n";
  }
}

} // namespace io
