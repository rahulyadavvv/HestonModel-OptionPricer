#include "argparse.h"
#include <gtest/gtest.h>
#include <string>
#include <vector>

/**
 * @brief Basic usage case.
 */
TEST(ArgparseTest, BasicCase) {
  std::vector<std::string> flags = {"--target", "--destination", "--overwrite"};
  int argc = 5;
  char *argv[] = {"move_file", "--target", "./public/secret.txt",
                  "--destination", "./private/secret.txt"};
  argmap parsed = argparse(argc, argv, flags);
  argmap expected{
      {"--target", {"./public/secret.txt"}},
      {"--destination", {"./private/secret.txt"}},
      {"--overwrite", {}},
  };
  EXPECT_EQ(parsed, expected);
}

/**
 * @brief When there is whitespace in the argument vector.
 */
TEST(ArgparseTest, WhitespaceCase) {
  std::vector<std::string> flags = {"--base", "--exponent"};
  int argc = 8;
  char *argv[] = {"pow", "", "", "--base", "3", "", "--exponent", "2"};
  argmap parsed = argparse(argc, argv, flags);
  argmap expected{{"--base", {"3"}}, {"--exponent", {"2"}}};
  EXPECT_EQ(parsed, expected);
}

/**
 * @brief When a flag is not in the argument vector.
 */
TEST(ArgparseTest, IgnoreCase) {
  std::vector<std::string> flags = {"--base", "--exponent", "--verbose"};
  int argc = 5;
  char *argv[] = {"pow", "--base", "3", "--exponent", "2"};
  argmap parsed = argparse(argc, argv, flags);
  argmap expected{{"--base", {"3"}}, {"--exponent", {"2"}}, {"--verbose", {}}};
  EXPECT_EQ(parsed, expected);
}
