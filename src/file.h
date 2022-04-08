#pragma once

#include <string>
#include <vector>

std::vector<std::string> getRandomWords(const std::string& filename, u_short numer_of_words);
std::vector<std::string> getAllWords(const std::string& filename);
void printWordLists(const std::string& filepath);