#include "io/layout_reader.h"
#include "io/rule_reader.h"
#include "io/result_writer.h"
#include "trace/pipeline.h"
#include "utils/logging.h"
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>

struct Cmd {
  std::string layout, rule, output;
  int threads = 1;
};

static bool parse_args(int argc, char** argv, Cmd& cmd) {
  for (int i = 1; i < argc; ++i) {
    std::string a = argv[i];
    if (a == "-layout" && i + 1 < argc) cmd.layout = argv[++i];
    else if (a == "-rule" && i + 1 < argc) cmd.rule = argv[++i];
    else if (a == "-output" && i + 1 < argc) cmd.output = argv[++i];
    else if (a == "-thread" && i + 1 < argc) {
      cmd.threads = std::max(1, std::atoi(argv[++i]));
    } else {
      std::fprintf(stderr, "Unknown/invalid arg: %s\n", a.c_str());
      return false;
    }
  }
  return !cmd.layout.empty() && !cmd.rule.empty() && !cmd.output.empty();
}

int main(int argc, char** argv) {
  Cmd cmd;
  if (!parse_args(argc, argv, cmd)) {
    std::fprintf(stderr, "Usage: trace -layout <file> -rule <file> [-thread n] -output <file>\n");
    return 64; // EX_USAGE
  }

  try {
    auto layout = io::read_layout(cmd.layout);
    auto rules  = io::read_rule(cmd.rule);
    trace::Pipeline pipeline(cmd.threads); // inside ensures >=1
    auto result = pipeline.run(layout, rules);
    io::write_result(cmd.output, result);
  } catch (const std::exception& e) {
    std::fprintf(stderr, "Error: %s\n", e.what());
    return 1;
  }
  return 0;
}
