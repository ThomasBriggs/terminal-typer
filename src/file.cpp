#include "file.h"
#include "error_handeling.h"
#include <algorithm>
#include <exception>
#include <filesystem>
#include <fstream>
#include <random>
#include <vector>

std::vector<std::string> getRandomWordsRepeat(std::ifstream& file, u_short n, u_short number_of_lines);
std::vector<std::string> getRandomWordsNoRepeat(std::ifstream& file, u_short n, u_short number_of_lines);
size_t getLineCount(std::ifstream& file);

size_t getLineCount(std::ifstream& file)
{
    auto pos = file.tellg();
    unsigned int number_of_lines = std::count(
                                       std::istreambuf_iterator<char>(file),
                                       std::istreambuf_iterator<char>(), '\n')
        + 1;
    file.seekg(pos);
    return number_of_lines;
}

std::vector<std::string> getRandomWords(const std::string& f, u_short n)
{
    std::ifstream file(f);
    checkIfFileCanBeOpened(file, f);
    size_t number_of_lines = getLineCount(file);
    if (n < number_of_lines)
        return getRandomWordsNoRepeat(file, n, number_of_lines);
    else
        return getRandomWordsRepeat(file, n, number_of_lines);
}

std::vector<std::string> getRandomWordsRepeat(std::ifstream& file, u_short n, u_short number_of_lines)
{
    file.seekg(0);
    std::vector<std::string> words(n);
    std::vector<u_short> line_indices(n);

    std::mt19937 gen(std::random_device().operator()());
    std::uniform_int_distribution<> dist(0, number_of_lines);

    for (auto&& i : line_indices)
        i = dist(gen);

    std::string line;
    int line_number = 0;
    while (std::getline(file, line)) {
        for (int i = 0; i < n; ++i) {
            if (line_number == line_indices[i]) {
                words[i] = line;
            }
        }
        line_number++;
    }

    return words;
}

std::vector<std::string> getRandomWordsNoRepeat(std::ifstream& file, u_short n, u_short number_of_lines)
{
    if (n > number_of_lines) {
        throw std::out_of_range("Not enough words in the file");
    }

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
                break;
            }
        }
        line_number++;
    }
    return words;
}

std::vector<std::string> getAllWords(const std::string& f)
{
    std::ifstream file(f);
    checkIfFileCanBeOpened(file, f);
    size_t numLines = getLineCount(file);
    std::vector<std::string> words(numLines);

    std::string line;
    size_t i = 0;
    while (std::getline(file, line)) {
        words[i] = line;
        i++;
    }
    return words;
}

void printWordLists(const std::string& filepath)
{
    std::vector<std::string> files;
    for (auto &&i : std::filesystem::directory_iterator(filepath))
    {
        std::cout << i.path().filename().c_str() << '\n';
    }
}
