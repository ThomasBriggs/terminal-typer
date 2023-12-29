#include "util.h"

float getAccuracy(const std::vector<std::string> &input, const std::vector<std::string> &goal)
{
    size_t denom = input.size();
    float correct = 0;
    for (size_t i = 0; i < input.size(); i++)
    {
        correct = input[i] == goal[i] ? correct + 1 : correct + 0;
    }
    return correct / denom * 100;
}

bool isCharCorrect(const std::string &currentWord, const std::string &inputWord)
{
    if (inputWord.size() > currentWord.size())
        return false;

    if (inputWord.back() == currentWord.at(inputWord.size() - 1))
        return true;

    return false;
}

bool isCharCorrectAtPos(const std::string &currentWord, const std::string &inputWord, const int pos)
{
    if (currentWord.size() == 0)
        return false;

    if (inputWord.size() == 0)
        return true;

    if (pos > currentWord.size())
        return false;

    return currentWord.at(pos) == inputWord.at(pos);
}

bool isInputCorrect(const std::string &word, const std::string &input)
{
    if (input.size() == 0)
        return true;

    if (input.size() > word.size())
        return false;

    for (size_t i = 0; i < input.size(); i++)
    {
        if (input.at(i) != word.at(i))
            return false;
    }

    return true;
}