#include "file.h"
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>

// size_t getLineCount(std::ifstream& file)
// {
//     auto pos = file.tellg();
//     unsigned int number_of_lines = std::count(
//         std::istreambuf_iterator<char>(file),
//         std::istreambuf_iterator<char>(),
//         '\n'
//     ) + 1;
//     file.seekg(pos);
//     return number_of_lines;
// }

size_t getLineCount(std::ifstream& file)
{
    auto pos = file.tellg();
    size_t count = 0;
    std::string s;
    while (std::getline(file, s))
    {
        count++;
    }
    file.seekg(pos);
    return count;
}

std::vector<std::string> getRandomWords(const std::string& f, u_short n)
{

    std::ifstream file(f);
    size_t number_of_lines = getLineCount(file);
    if (n > number_of_lines) { std::__throw_out_of_range("Not enough words in the file"); }

    file.seekg(0);
    std::vector<std::string> words(n);
    std::vector<u_short> line_indices(number_of_lines);
    std::iota(begin(line_indices), end(line_indices), 0);
    std::shuffle(begin(line_indices), end(line_indices),
        std::mt19937(std::random_device().operator()()));
    std::string line;
    int line_number = 0;
    while (std::getline(file, line)) {
        for (int i = 0; i < n; ++i) {
            if (line_number == line_indices[i]) {
                words[i] = line;
            }
        }
        ++line_number;
    }
    return words;
}

std::vector<std::string> getAllWords(const std::string& f)
{
    std::ifstream file(f);
    size_t numLines = getLineCount(file);
    std::vector<std::string> words(numLines);

    std::string line;
    size_t i = 0;
    while (std::getline(file, line))
    {
        words[i] = line;
        i++;
    }
    return words;
}
