#include "typer.h"
#include "file.h"

int main(int argc, char const *argv[])
{
    typer(getAllWords("../res/aladin.txt"));
    return 0;
}
