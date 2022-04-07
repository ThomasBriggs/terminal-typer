#pragma once

#include <filesystem>
#include <fstream>
#include <iostream>

void checkModeSet(bool mode_set);
void checkIfFileCanBeOpened(const std::ifstream& file, const std::string& filepath);