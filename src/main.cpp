#include "file.h"
#include "typer.h"
#include <iostream>

int main(int argc, char const* argv[])
{
    std::vector<std::string> words;

    if (argc == 1) {
        words = getRandomWords("/home/thomas/terminal-typer/top_100.txt", 50);
        std::cout << "Test" << '\n';
    }

    typer(words);
    return 0;
}
