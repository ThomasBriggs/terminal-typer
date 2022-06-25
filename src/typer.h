#pragma once

#include <string>
#include <vector>

class typer
{
private:
    std::vector<std::string> word_list;
    std::unique_ptr<WINDOW, void (*)(WINDOW*)> ncurses_setup();
public:
    typer(std::vector<std::string> words);
    ~typer();
    int run();
};


