#include "file.h"
#include "typer.h"
#include <iostream>
#include <string>

int main(int argc, char const* argv[])
{
    std::vector<std::string> words;

    if (argc == 1)
        words = getRandomWords("/home/thomas/terminal-typer/top_100.txt", 50);
    else if (argc == 2) {
        int num = std::stoi(std::string(argv[1]));
        if (num < 1) {
            std::cerr << "Please enter a number above 0!\n";
            exit(1);
        } else if (num > 101)
            words = getRandomWords("/home/thomas/terminal-typer/top_1000.txt", num);
        else
            words = getRandomWords("/home/thomas/terminal-typer/top_100.txt", num);
    }

    typer(words);
    return 0;
}
