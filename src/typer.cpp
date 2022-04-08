#include "typer.h"
#include "display.h"
#include "file.h"
#include "util.h"
#include "ncurses.h"
#include <algorithm>
#include <cctype>
#include <chrono>
#include <iostream>

void ncurses_setup()
{
    initscr();
    use_default_colors();
    assume_default_colors(-1, -1);
    cbreak();
    keypad(stdscr, true);
    noecho();
    start_color();
    curs_set(0);
}

int typer(std::vector<std::string> words)
{
    ncurses_setup();

    WINDOW* inputWin = getInputWin();
    WINDOW* promptWin = getPromptWin();
    refresh();
    wrefresh(inputWin);
    wrefresh(promptWin);

    u_short numWords = words.size();
    std::vector<std::string> typedWords(words.size());
    int input;
    int curWord = 0;
    size_t charsTyped = 0;
    size_t correctCharsTyped = 0;

    bool active = true;
    typedef std::chrono::system_clock clock;
    auto start = clock::time_point::min();

    displayWords(promptWin, words, curWord, typedWords);
    wrefresh(promptWin);
    wmove(inputWin, 1, 1);
    while (active) {
        input = getch();
        if (start == clock::time_point::min())
            start = clock::now();

        switch (input) {
        case KEY_BACKSPACE:
        case 127:
            if (typedWords[curWord].empty())
                curWord = std::max(0, curWord - 1);
            else
                (typedWords[curWord].pop_back());
            displayInput(inputWin, typedWords[curWord]);
            displayWords(promptWin, words, curWord, typedWords);
            break;
        case ' ':
            curWord += 1;
            if (curWord >= words.size())
                active = false;
            displayInput(inputWin, typedWords[curWord]);
            displayWords(promptWin, words, curWord, typedWords);
            break;
        default:
            if (typedWords[curWord].size() == getmaxx(inputWin) - 2)
                break;
            charsTyped++;
            typedWords[curWord] += input;
            if (isCharCorrect(words[curWord], typedWords[curWord]))
                correctCharsTyped++;
            displayInput(inputWin, typedWords[curWord]);
            displayWords(promptWin, words, curWord, typedWords);
            break;
        }
        wrefresh(inputWin);
        wrefresh(promptWin);
    }
    endwin();
    auto stop = clock::now();
    displayResults(std::chrono::duration_cast<std::chrono::milliseconds>(stop - start),
        charsTyped, correctCharsTyped, numWords, typedWords, words);
    return 0;
}