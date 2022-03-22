#include "display.h"
#include <curses.h>

void displayWords(WINDOW* win, std::vector<std::string> words, int currentWord, std::vector<std::string> inputWords)
{
    init_pair(5, COLOR_BLUE, -1);
    init_pair(6, COLOR_RED, -1);
    init_pair(7, COLOR_GREEN, -1);
    short colour;
    u_int min_y = 1, min_x = 1, max_x = getmaxx(win) - 1;
    wmove(win, min_y, min_x);
    auto&& curWord = words[0];
    for(size_t i = 0; i < words.size(); i++)
    {
        curWord = words[i];
        //Move cursor down if word won't fit on the line
        if (!(getcurx(win) + curWord.size() < max_x)) { wmove(win, getcury(win) + 1, min_x); }
        if (i < currentWord)
        {
            if (inputWords[i] == words[i]) colour = 7;
            else colour = 6;
        }
        //If the word to be displayed is the current word turn it blue
        if (i == currentWord) colour = 5;
        wattron(win, COLOR_PAIR(colour));
        wprintw(win, (curWord + ' ').c_str());
        wattroff(win, COLOR_PAIR(colour));
        colour = 0;
    }
}

void displayInput(WINDOW* win, const std::string& s)
{
    clearInput(win);
    wmove(win, 1, 1);
    wprintw(win, s.c_str());
}


void clearInput(WINDOW* win)
{
    werase(win);
    drawInput(win);
}

WINDOW* getInputWin()
{
    WINDOW* win = newwin(3, getmaxx(stdscr), 0, 0);
    drawInput(win);
    return win;
}

WINDOW* getPromptWin()
{
    WINDOW* win = newwin(getmaxy(stdscr) - 3, getmaxx(stdscr), 3, 0);
    init_pair(3, COLOR_YELLOW, -1);
    wattron(win, COLOR_PAIR(3));
    box(win, 0, 0);
    wattroff(win, COLOR_PAIR(3));
    wattron(win, A_BOLD);
    mvwprintw(win, 0, 1, "Prompt");
    wattroff(win, A_BOLD);
    return win;
}

void drawInput(WINDOW * win)
{
    init_pair(2, COLOR_CYAN, -1);
    wattron(win, COLOR_PAIR(2));
    box(win, 0, 0);
    wattroff(win, COLOR_PAIR(2));
    wattron(win, A_BOLD);
    mvwprintw(win, 0, 1, "Input");
    wattroff(win, A_BOLD);
}