/**
 * @file
 * @brief Implementation for `argparse`.
 */

#include "argparse.h"
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iterator>
#include <optional>
#include <string>
#include <utility>
#include <vector>

argmap argparse(int argc, char *argv[], std::vector<std::string> flags) {
  argmap parsed = {};
  // set `parsed` keys to `flags` and map to empty vector
  std::transform(flags.begin(), flags.end(),
                 std::inserter(parsed, parsed.end()), [](std::string flag) {
                   return std::make_pair(flag, std::vector<std::string>());
                 });
  // iterate `argv` and insert arguments into `parsed`
  std::optional<std::string> flag = {};
  for (size_t i = 1; i < argc; i++) {
    // skip empty string (when there are consecutive whitespace)
    if (strlen(argv[i]) == 0) {
      continue;
    }
    // reset `flag` if in `flags` else parse argument
    if (std::find(flags.begin(), flags.end(), argv[i]) != flags.end()) {
      flag.emplace(argv[i]);
    } else if (flag.has_value()) {
      // insert argument to end of the vector
      parsed[flag.value()].insert(parsed[flag.value()].end(), argv[i]);
    }
  }
  return parsed;
}
