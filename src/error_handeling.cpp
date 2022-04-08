#include "error_handeling.h"

void checkModeSet(bool mode_set)
{
    if (mode_set) {
        std::cerr << "Only set --words, or --quote, not both!, see --help for more info\n";
        exit(1);
    }
}

void checkIfFileCanBeOpened(const std::ifstream& file, const std::string& filepath)
{
    if (!file.is_open())
        throw std::filesystem::filesystem_error("The file could not be opened", filepath, std::error_code(2, std::system_category()));
}
