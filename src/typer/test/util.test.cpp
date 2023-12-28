#include "util.h"
#include "gtest/gtest.h"

class UtilTest : public testing::Test
{
};

TEST_F(UtilTest, ReturnFalseIfInputIsLarger)
{
  const std::string inputWord = "Hello";
  const std::string testWord = "h";
  bool output = isCharCorrect(testWord, inputWord);
  ASSERT_EQ(output, false);
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}