#pragma once

#include "util.h"
#include <chrono>
#include <cmath>
#include <curses.h>
#include <iostream>
#include <string>
#include <vector>

void displayWords(WINDOW* win, std::vector<std::string> words, int currentWord, std::vector<std::string> inputWords);
void displayInput(WINDOW* win, const std::string& s);
void clearInput(WINDOW* win);
void drawInput(WINDOW* win);
WINDOW* getInputWin();
WINDOW* getPromptWin();
void displayResults(const std::chrono::milliseconds& duration, const size_t& charsTyped, const size_t& correctCharsTyped, const size_t& numWords,
    const std::vector<std::string>& inputWords, const std::vector<std::string>& words);