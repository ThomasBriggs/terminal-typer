#pragma once

#include "util.h"
#include <chrono>
#include <cmath>
#include <curses.h>
#include <iostream>
#include <string>
#include <vector>

void displayWords(WINDOW* const win, const std::vector<std::string>& words, int currentWord, const std::vector<std::string>& inputWords);
void displayInput(WINDOW* const win, const std::string& s);
void clearInput(WINDOW* const win);
void drawInput(WINDOW* const win);
WINDOW* getInputWin();
WINDOW* getPromptWin();
void displayResults(const std::chrono::milliseconds& duration, const size_t& charsTyped, const size_t& correctCharsTyped, const size_t& numWords,
    const std::vector<std::string>& inputWords, const std::vector<std::string>& words);