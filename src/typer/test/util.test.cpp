#include "util.h"
#include "gtest/gtest.h"

TEST(isCharCorrect, ReturnFalseIfInputIsLarger)
{
  const std::string inputWord = "Hello";
  const std::string testWord = "h";
  bool output = isCharCorrect(testWord, inputWord);
  ASSERT_EQ(output, false);
};

TEST(isCharCorrect, ReturnTrueIfCharMatches)
{
  std::string inputWord, testWord;
  bool output;
  testWord = "h";
  inputWord = "h";
  output = isCharCorrect(testWord, inputWord);
  ASSERT_EQ(output, true);

  testWord = "he";
  inputWord = "he";
  output = isCharCorrect(testWord, inputWord);
  ASSERT_EQ(output, true);

  testWord = "hello";
  inputWord = "hello";
  output = isCharCorrect(testWord, inputWord);
  ASSERT_EQ(output, true);

  testWord = "hello";
  inputWord = "h";
  output = isCharCorrect(testWord, inputWord);
  ASSERT_EQ(output, true);
}

TEST(isCharCorrect, ReturnFalseIfCharDontMatches)
{
  std::string inputWord, testWord;
  bool output;
  testWord = "h";
  inputWord = "e";
  output = isCharCorrect(testWord, inputWord);
  ASSERT_EQ(output, false);

  testWord = "he";
  inputWord = "hl";
  output = isCharCorrect(testWord, inputWord);
  ASSERT_EQ(output, false);

  testWord = "he";
  inputWord = "hello";
  output = isCharCorrect(testWord, inputWord);
  ASSERT_EQ(output, false);
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}