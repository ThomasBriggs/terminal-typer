#include "display.h"
#include "ncurses.h"

void displayWords(WINDOW* const win, const std::vector<std::string>& words, int currentWord, const std::vector<std::string>& inputWords)
{
    init_pair(5, COLOR_BLUE, -1);
    init_pair(6, COLOR_RED, -1);
    init_pair(7, COLOR_GREEN, -1);
    short colour;
    u_int min_y = 1, min_x = 1, max_x = getmaxx(win) - 1;
    wmove(win, min_y, min_x);
    const std::string* curWord;
    for (size_t i = 0; i < words.size(); i++) {
        curWord = &words[i];
        // Move cursor down if word won't fit on the line
        if (!(getcurx(win) + curWord->size() < max_x)) {
            wmove(win, getcury(win) + 1, min_x);
        }

        // Display previous words
        if (i < currentWord) {
            if (inputWords[i] == words[i]) // If the displayed matches the word typed, make it green
                colour = 7;
            else // Make if red
                colour = 6;
        }

        // Display the current word
        if (i == currentWord)
            if (isInputCorrect(words[currentWord], inputWords[currentWord]))
                colour = 5;
            else

                colour = 6;

        wattron(win, COLOR_PAIR(colour));
        wprintw(win, curWord->c_str());
        wprintw(win, " ");
        wattroff(win, COLOR_PAIR(colour));
        colour = 0;
    }
}

void displayInput(WINDOW* const win, const std::string& s)
{
    clearInput(win);
    wmove(win, 1, 1);
    wprintw(win, s.c_str());
}

void clearInput(WINDOW* const win)
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
    drawPrompt(win);
    return win;
}

void drawPrompt(WINDOW* const win)
{
    init_pair(3, COLOR_YELLOW, -1);
    wattron(win, COLOR_PAIR(3));
    box(win, 0, 0);
    wattroff(win, COLOR_PAIR(3));
    wattron(win, A_BOLD);
    mvwprintw(win, 0, 1, "Prompt");
    wattroff(win, A_BOLD);
}

void drawInput(WINDOW* const win)
{
    init_pair(2, COLOR_CYAN, -1);
    wattron(win, COLOR_PAIR(2));
    box(win, 0, 0);
    wattroff(win, COLOR_PAIR(2));
    wattron(win, A_BOLD);
    mvwprintw(win, 0, 1, "Input");
    wattroff(win, A_BOLD);
}

void displayResults(const std::chrono::milliseconds& duration, const size_t& charsTyped, const size_t& correctCharsTyped, const size_t& numWords,
    const std::vector<std::string>& inputWords, const std::vector<std::string>& words)
{
    auto time = duration.count() / 60000.f;
    auto gross_wpm = std::roundf((charsTyped / 5) / (duration.count() / 60000.f) * 100) / 100;
    auto net_wpm = gross_wpm - ((charsTyped - correctCharsTyped) / time);

    std::cout << "Time: " << duration.count() << "ms\n";
    std::cout << "WPM (chars): " << net_wpm << '\n';
    std::cout << "WPM (Gross): " << gross_wpm << '\n';
    std::cout << "Accuracy (chars): " << (float)correctCharsTyped / charsTyped * 100 << "%\n";
    std::cout << "Accuracy (words): " << getAccuracy(inputWords, words) << "%\n";
    std::cout << "Chars typed: " << charsTyped << ", Correct Chars Typed: " << correctCharsTyped << '\n';
}