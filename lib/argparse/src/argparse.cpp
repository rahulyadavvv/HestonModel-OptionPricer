/**
 * @file
 * @brief Implementation for `argparse`.
 */

#include "argparse.h"
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <exception>
#include <iterator>
#include <optional>
#include <string>
#include <utility>
#include <vector>

argmap argparse(int argc, char *argv[], std::vector<std::string> flags) {
  argmap parsed = {};
  // set `parsed` keys to `flags` the value is initialized as empty
  std::transform(flags.begin(), flags.end(),
                 std::inserter(parsed, parsed.end()), [](std::string flag) {
                   return std::make_pair(
                       flag, std::optional<std::vector<std::string>>{});
                 });
  if (argc == 1) {
    return parsed;
  }
  // iterate `argv` and insert arguments into `parsed`
  std::optional<std::string> flag = {};
  for (size_t i = 1; i < argc; i++) {
    char *arg{argv[i]};

    // skip empty string (when there is consecutive whitespace)
    if (strlen(arg) == 0) {
      continue;
    }
    // reset `flag` if in `flags` else parse argument
    if (std::find(flags.begin(), flags.end(), arg) != flags.end()) {
      flag.emplace(arg);
      // indicate that the `flag` has been specified, throw if already has
      if (parsed[flag.value()].has_value()) {
        throw std::exception();
      } else {
        parsed[flag.value()].emplace(std::vector<std::string>{});
      }
    } else if (flag) {
      std::string key = flag.value();
      // insert argument to end of the vector
      if (parsed[key]) {
        parsed[key]->push_back(arg);
      } else {
        parsed[key].emplace(std::vector<std::string>{arg});
      }
    }
  }
  return parsed;
}
