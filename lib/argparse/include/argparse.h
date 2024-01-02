/**
 * @file argparse.h
 * @brief Header file for `argparse`.
 */

#ifndef ARGPARSE_H
#define ARGPARSE_H

#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

using argmap =
  std::unordered_map<std::string, std::optional<std::vector<std::string>>>;

/**
 * @brief Command line argument parser.
 *
 * @param argc The argument count given by command line.
 * @param argv The argument vector given by command line.
 * @param flags The flags to parse arguments for, usually "-FLAG" or "--FLAG".
 * @return An unordered map from `flags` to an optional vector of argument
 * strings.
 *
 * - If an element in `flags` does not appear in `argv` then the resultant value
 * is empty, i.e. `("--FLAG", std::nullopt)`.
 * - An element from `flags` can appear multiple times in `argv`, for instance
 * `"--FLAG e1 --FLAG e2"` will result in a pair `("--FLAG", {"e1", "e2"})`.
 */
argmap argparse(int argc, char *argv[], std::vector<std::string> flags);

#endif  // !ARGPARSE_H
