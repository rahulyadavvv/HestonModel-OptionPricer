/**
 * @file argparse.cpp
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

argmap argparse(int argc, char *argv[], std::vector<std::string> flags)
{
  argmap result = {};
  // create pair of `flag` and optional vector
  auto init_flag = [](std::string flag) {
    return std::make_pair(flag, std::optional<std::vector<std::string>>{});
  };
  std::transform(flags.begin(), flags.end(),
                 std::inserter(result, result.end()), init_flag);
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
      // initialize vector if empty
      if (!result[flag.value()]) {
        result[flag.value()].emplace(std::vector<std::string>{});
      }
    }
    else if (flag) {
      std::string key = flag.value();
      // insert argument to end of the vector
      if (result[key]) {
        result[key]->push_back(arg);
      }
      else {
        result[key].emplace(std::vector<std::string>{arg});
      }
    }
  }
  return result;
}
