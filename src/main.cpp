#include "file.h"
#include "typer.h"

int main(int argc, char const* argv[])
{
    size_t numWords = 50;
    auto words = getRandomWords("/home/thomas/terminal-typer/src/top_1000.txt", numWords);
    typer(words);
    return 0;
}
