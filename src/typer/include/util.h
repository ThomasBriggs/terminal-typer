#pragma once

#include <string>
#include <vector>

float getAccuracy(const std::vector<std::string>& input, const std::vector<std::string>& goal);
bool isCharCorrect(const std::string& currentWord, const std::string& inputWord);
bool isInputCorrect(const std::string& word, const std::string& input);
bool isCharCorrectAtPos(const std::string &currentWord, const std::string &inputWord, const int pos);
