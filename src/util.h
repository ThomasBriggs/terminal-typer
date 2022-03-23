#pragma once

#include <vector>
#include <string>

float getAccuracy(const std::vector<std::string>& input, const std::vector<std::string>& goal);
double isCharCorrect(const std::string& currentWord, const std::string& inputWord);

