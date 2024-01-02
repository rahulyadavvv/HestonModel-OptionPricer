/**
 * @file argparse_test.cpp
 * @brief Tests related to `argparse` implementation.
 */

#include "argparse.h"

#include <gtest/gtest.h>
#include <optional>
#include <string>
#include <vector>

using vecs = std::vector<std::string>;
using optvecs = std::optional<vecs>;

/**
 * @brief Basic usage case.
 */
TEST(ArgparseTest, BasicCase)
{
  char pow_fn[] = "pow";
  char base_flag[] = "--base";
  char base_input[] = "3";
  char exp_flag[] = "--exp";
  char exp_input[] = "2";
  std::vector<std::string> flags{base_flag, exp_flag};
  int argc = 5;
  char *argv[]{pow_fn, base_flag, base_input, exp_flag, exp_input};
  argmap parsed = argparse(argc, argv, flags);
  argmap expected{
    {base_flag, optvecs{vecs{base_input}}},
    {exp_flag, optvecs{vecs{exp_input}}},
  };
  EXPECT_EQ(parsed, expected);
}

/**
 * @brief When there is whitespace in the argument vector.
 */
TEST(ArgparseTest, WhitespaceCase)
{
  char ws[] = "";
  char pow_fn[] = "pow";
  char base_flag[] = "--base";
  char base_input[] = "3";
  char exp_flag[] = "--exp";
  char exp_input[] = "2";
  std::vector<std::string> flags{base_flag, exp_flag};
  int argc = 11;
  char *argv[]{pow_fn, ws,       ws, base_flag, ws, base_input,
               ws,     exp_flag, ws, exp_input, ws};
  argmap parsed = argparse(argc, argv, flags);
  argmap expected{
    {base_flag, optvecs{vecs{base_input}}},
    {exp_flag, optvecs{vecs{exp_input}}},
  };
  EXPECT_EQ(parsed, expected);
}

/**
 * @brief Should be an empty value when no flag is passed.
 */
TEST(ArgparseTest, NoFlagCase)
{
  char pow_fn[] = "pow";
  char base_flag[] = "--base";
  char base_input[] = "3";
  char exp_flag[] = "--exp";
  char exp_input[] = "2";
  char verb_flag[] = "--verbose";
  std::vector<std::string> flags = {base_flag, exp_flag, verb_flag};
  int argc = 5;
  char *argv[]{pow_fn, base_flag, base_input, exp_flag, exp_input};
  argmap parsed = argparse(argc, argv, flags);
  argmap expected{
    {base_flag, optvecs{vecs{base_input}}},
    {exp_flag, optvecs{vecs{exp_input}}},
    {verb_flag, optvecs{}},
  };
  EXPECT_EQ(parsed, expected);
}

/**
 * @brief Should be an empty vector when no argument is passed.
 */
TEST(ArgparseTest, OnlyFlagCase)
{
  char pow_fn[] = "pow";
  char base_flag[] = "--base";
  char exp_flag[] = "--exp";
  std::vector<std::string> flags = {base_flag, exp_flag};
  int argc = 3;
  char *argv[]{pow_fn, base_flag, exp_flag};
  argmap parsed = argparse(argc, argv, flags);
  argmap expected{
    {base_flag, optvecs{vecs{}}},
    {exp_flag, optvecs{vecs{}}},
  };
  EXPECT_EQ(parsed, expected);
}

/**
 * @brief Duplicated flags should extend the arguments vector.
 */
TEST(ArgparseTest, DuplicateFlagCase)
{
  char pow_fn[] = "pow";
  char base_flag[] = "--base";
  char base_input[] = "3";
  char exp_flag[] = "--exp";
  char another_input[] = "2";
  std::vector<std::string> flags = {base_flag, exp_flag};
  int argc = 5;
  char *argv[]{pow_fn, base_flag, base_input, base_flag, another_input};
  argmap parsed = argparse(argc, argv, flags);
  argmap expected{
    {base_flag, optvecs{vecs{base_input, another_input}}},
    {exp_flag, optvecs{}},
  };
  EXPECT_EQ(parsed, expected);
}
