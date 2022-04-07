#include "cxxopts.hpp"
#include "file.h"
#include "typer.h"
#include <filesystem>
#include <iostream>
#include <string>

int main(int argc, char const* argv[])
{
    std::filesystem::path root = "../res";
    std::vector<std::string> words;
    bool mode_set = false;

    cxxopts::Options options("Terminal-typer", "A terminal typing game");
    options.add_options()(
        "q, quote", "Type a random quote", cxxopts::value<std::string>()->implicit_value(""))(
        "w, words", "Type 50 random words from top 100 words, or --words=X where X is the number of words", cxxopts::value<int>()->implicit_value("50")->default_value("50"))(
        "words-list", "The word list to choose random words from, if used with --quote, this will have no effect", cxxopts::value<std::string>()->default_value("top_100.txt"))(
        "h, help", "Print usage");

    auto results = options.parse(argc, argv);

    if (argc == 1)
        words = getRandomWords(root.append(results["words-list"].as<std::string>()), results["words"].as<int>());

    if (results.count("help")) {
        std::cout << options.help() << '\n';
        exit(0);
    }

    if (results.count("quote")) {
        mode_set = true;
        const std::string& quotePath = results["quote"].as<std::string>();
        if (quotePath == "")
            words = getAllWords(root.append("aladin.txt"));
        else {
            words = getAllWords(quotePath);
        }
    }

    if (results.count("words")) {
        mode_set = true;
        words = getRandomWords(root.append(results["words-list"].as<std::string>()), results["words"].as<int>());
    }

    if (!mode_set)
        words = getRandomWords(root.append(results["words-list"].as<std::string>()), results["words"].as<int>());

    typer(words);
    return 0;
}
