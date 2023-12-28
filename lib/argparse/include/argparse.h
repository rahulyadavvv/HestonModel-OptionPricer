/**
 * @file
 * @brief Header file for `argparse`.
 */

#ifndef ARGPARSE_H
#define ARGPARSE_H

#include <string>
#include <unordered_map>
#include <vector>

using argmap = std::unordered_map<std::string, std::vector<std::string>>;

/**
 * @brief Command line argument parser.
 *
 * @param argc The argument count entered into the command line.
 * @param argv The argument vector given by the command line.
 * @param flags The flags you want to parse arguments for, usually "-[ flag ]"
 * or "--[ flag ]".
 * @return Unordered map with the keys matching the `flags`, if a flag was not
 * in `argv` the value maps to an empty std::vector.
 */
argmap argparse(int argc, char *argv[], std::vector<std::string> flags);

#endif // !ARGPARSE_H
