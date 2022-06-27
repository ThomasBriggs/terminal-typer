#include "cxxopts.hpp"
#include "error_handeling.h"
#include "file.h"
#include "typer.h"
#include <filesystem>
#include <iostream>
#include <string>

cxxopts::Options setupArgs()
{
    cxxopts::Options options("Terminal-typer", "A terminal typing game");
    options.add_options()(
        "q, quote", "Type a random quote", cxxopts::value<std::string>()->implicit_value(""))(
        "w, words", "Type 50 random words from top 100 words, or --words = X where X is the number of words ", cxxopts::value<int>()->implicit_value("50")->default_value("50"))(
        "words-list", "The word list to choose random words from, if used with --quote, this will have no effect", cxxopts::value<std::string>()->default_value("top_100.txt"))(
        "list", "List the avilables word lists")(
        "h, help", "Print usage");

    return options;
}

std::filesystem::path setupPath(char const* argv[])
{
    std::filesystem::path root = argv[0];
    if (root.parent_path().has_parent_path())
        root = root.parent_path().parent_path().append("res");
    else
        root = "../res";
    return root;
}

int main(int argc, char const* argv[])
{
    auto root = setupPath(argv);
    auto options = setupArgs();

    std::vector<std::string> words;
    bool mode_set = false;
    bool non_mode_set = false;

    cxxopts::ParseResult results;
    try {
        results = options.parse(argc, argv);
    } catch (cxxopts::option_syntax_exception& e) {
        std::cerr << "Unknown syntax - " << e.what() << '\n';
        std::cout << options.help();
        exit(1);
    } catch (cxxopts::option_not_exists_exception& e) {
        std::cerr << "Unknown option - " << e.what() << '\n';
        std::cout << options.help();
        exit(1);
    }

    // If no arguments are given, set the words to be the default arguments and go to the main loop,
    // skip checking args as none are given.
    if (argc == 1) {
        mode_set = true;
        words = getRandomWords(root.append(results["words-list"].as<std::string>()), results["words"].as<int>());
        goto main;
    }

    if (results.count("help")) {
        std::cout << options.help() << '\n';
        exit(0);
    }

    if (results.count("quote")) {
        checkModeSet(mode_set);
        mode_set = true;
        const std::string& quotePath = results["quote"].as<std::string>();
        if (quotePath == "")
            words = getQuote();
        else {
            words = getAllWords(quotePath);
        }

    }

    if (results.count("words")) {
        checkModeSet(mode_set);
        mode_set = true;
        words = getRandomWords(root.append(results["words-list"].as<std::string>()), results["words"].as<int>());
    }

    if (results.count("list-resources")) {
        printWordLists(root.c_str());
        exit(0);
    }

    if (!mode_set)
        words = getRandomWords(root.append(results["words-list"].as<std::string>()), results["words"].as<int>());

main:
    Typer(words).run();
    return 0;
}
