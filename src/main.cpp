#include "file.h"
#include "typer.h"
#include <filesystem>
#include <iostream>
#include <string>

int main(int argc, char const* argv[])
{
    std::filesystem::path root = "../res";
    std::vector<std::string> words;

    if (argc == 1)
        words = getRandomWords(root.append("top_100.txt"), 50);
    else if (argc == 2) {
        int num;
        try {
            num = std::stoi(std::string(argv[1]));
        } catch (std::invalid_argument& e) {
            std::cerr << "Must be a integer!\n";
            exit(1);
        }

        if (num < 1) {
            std::cerr << "Integet must be > 0!\n";
            exit(1);
        } else
            words = getRandomWords(root.append("top_100.txt"), num);
    } else {
        std::cerr << "RTFM!\n";
        exit(1);
    }

    typer(words);
    return 0;
}
