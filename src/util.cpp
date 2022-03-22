#include "util.h"

float getAccuracy(std::vector<std::string> input, std::vector<std::string> goal)
{
    size_t denom = input.size();
    float correct = 0;
    for (size_t i = 0; i < input.size(); i++)
    {
        correct = input[i] == goal[i] ? correct + 1 : correct + 0;
    }
    return correct/denom * 100;
}