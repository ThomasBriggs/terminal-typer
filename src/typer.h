#pragma once

#include "display.h"
#include "file.h"
#include "ncurses.h"
#include "util.h"
#include <algorithm>
#include <cctype>
#include <chrono>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Typer {
private:
    std::unique_ptr<WINDOW, void (*)(WINDOW*)> scr;
    std::vector<std::string> words;
    WINDOW* inputWin;
    WINDOW* promptWin;
    u_short numWords;
    bool active;
    std::vector<std::string> typedWords;
    int input;
    int curWord;
    size_t charsTyped;
    size_t correctCharsTyped;

    std::vector<std::string> word_list;
    std::unique_ptr<WINDOW, void (*)(WINDOW*)> ncurses_setup();

public:
    Typer(std::vector<std::string> words);
    int run();
};
