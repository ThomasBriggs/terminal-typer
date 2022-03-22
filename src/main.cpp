#include <curses.h>
#include <iostream>
#include "display.h"
#include "file.h"
#include <cctype>
#include <algorithm>
#include <chrono>
#include <cmath>
#include "util.h"

int main()
{
    initscr();
    use_default_colors();
    assume_default_colors(-1, -1);
    cbreak();
    keypad(stdscr, true);
    noecho();
    start_color();
    curs_set(0);

    u_short numWords = 50;

    WINDOW* inputWin = getInputWin();
    WINDOW* promptWin = getPromptWin();
    refresh();
    wrefresh(inputWin);
    wrefresh(promptWin);

    auto words = getRandomWords
    (
        "/home/thomas/Documents/cpp-examples/typer-racer/src/top_1000.txt",
        numWords
    );

    std::vector<std::string> inputWords(words.size());
    int input;
    int curWord = 0;
    displayWords(promptWin, words, curWord, inputWords);
    wrefresh(promptWin);

    bool active = true;
    wmove(inputWin, 1, 1);
    typedef std::chrono::system_clock clock;
    clock::time_point start = clock::time_point::min();

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
        else if (input == 127)
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
    clock::time_point stop = clock::now();
    endwin();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Time: " << duration.count() << "ms" << '\n';
    std::cout << "WPM (chars): " << std::roundf(((charsTyped / 5) / (duration.count() / 60000.f)) * 100) / 100 << '\n';
    std::cout << "WPM (words): " << std::roundf(numWords / (duration.count() / 60000.f) * 100) / 100 << '\n';
    std::cout << "Accuracy: " << getAccuracy(inputWords, words) << '%' << '\n';
    return 0;
}
