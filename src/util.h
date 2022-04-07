#pragma once

#include <vector>
#include <string>

float getAccuracy(const std::vector<std::string>& input, const std::vector<std::string>& goal);
bool isCharCorrect(const std::string& currentWord, const std::string& inputWord);
bool isInputCorrect(const std::string& word, const std::string& input);
