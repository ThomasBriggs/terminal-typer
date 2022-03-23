#include "util.h"

float getAccuracy(const std::vector<std::string>& input, const std::vector<std::string>& goal)
{
    size_t denom = input.size();
    float correct = 0;
    for (size_t i = 0; i < input.size(); i++) {
        correct = input[i] == goal[i] ? correct + 1 : correct + 0;
    }
    return correct / denom * 100;
}

double isCharCorrect(const std::string& currentWord, const std::string& inputWord)
{
    if (inputWord.size() > currentWord.size())
        return false;

    if (inputWord.back() == currentWord.at(inputWord.size() - 1))
        return true;

    return false;
}