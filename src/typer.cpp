#include <curses.h>
#include <iostream>
#include "display.h"
#include "file.h"
#include <cctype>
#include <algorithm>
#include <chrono>
#include "util.h"
#include "typer.h"

int typer(std::vector<std::string> words)
{
    initscr();
    use_default_colors();
    assume_default_colors(-1, -1);
    cbreak();
    keypad(stdscr, true);
    noecho();
    start_color();
    curs_set(0);

    u_short numWords = words.size();

    WINDOW* inputWin = getInputWin();
    WINDOW* promptWin = getPromptWin();
    refresh();
    wrefresh(inputWin);
    wrefresh(promptWin);

    std::vector<std::string> inputWords(words.size());
    int input;
    int curWord = 0;
    displayWords(promptWin, words, curWord, inputWords);
    wrefresh(promptWin);

    bool active = true;
    wmove(inputWin, 1, 1);
    typedef std::chrono::system_clock clock;
    auto start = clock::time_point::min();

    u_int charsTyped = 0;
    while (active)
    {
        input = getch();
        if (start == clock::time_point::min()) start = clock::now();
        if (std::isalpha(input) || std::isdigit(input))
        {
            charsTyped++;
            inputWords[curWord] += input;
            displayInput(inputWin, inputWords[curWord]);
        }
        else if (input == KEY_BACKSPACE)
        {
            if (inputWords[curWord].empty()) curWord = std::max(0, curWord - 1);
            else (inputWords[curWord].pop_back());
            displayWords(promptWin, words, curWord, inputWords);
            displayInput(inputWin, inputWords[curWord]);
        }
        else if (input == ' ')
        {
            curWord += 1;
            if (curWord >= words.size())
            {
                active = true;
                break;
            }
            displayInput(inputWin, inputWords[curWord]);
            displayWords(promptWin, words, curWord, inputWords);
        }
        wrefresh(inputWin);
        wrefresh(promptWin);
    }
    endwin();
    auto stop = clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    displayResults(duration, charsTyped, numWords, inputWords, words);
    return 0;
}