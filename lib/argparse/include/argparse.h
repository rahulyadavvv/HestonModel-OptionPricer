/**
 * @file
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
 * @param argc The argument count entered into the command line.
 * @param argv The argument vector given by the command line.
 * @param flags The flags you want to parse arguments for, usually "-FLAG"
 * or "--FLAG".
 * @return Unordered map with the keys matching the `flags`, if a flag was not
 * in `argv` the value is empty and if no argument is passed, then empty vector.
 */
argmap argparse(int argc, char *argv[], std::vector<std::string> flags);

#endif // !ARGPARSE_H
