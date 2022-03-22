#include <string>
#include <iostream>
#include <numeric>
#include <vector>
#include "file.h"
#include <chrono>

int main(int argc, char const* argv[])
{
    std::vector<std::string> words = getAllWords(
        "/home/thomas/Documents/cpp-examples/typer-racer/src/top_1000.txt");
    std::vector<std::string> big(100000);
    for (size_t i = 0; i < 100; i++)
    {
        std::copy(words.begin(), words.end(), big.begin()+100*i);
    }

    int l;
    auto s1 = std::chrono::high_resolution_clock::now();
    l = std::accumulate(big.begin(), big.end(), 0, [](int cur, std::string& str) { return cur + str.size();});
    auto e1 = std::chrono::high_resolution_clock::now();
    auto d1 = std::chrono::duration_cast<std::chrono::nanoseconds>(e1 - s1);
    std::cout << l << " Time: " << d1.count() << "ns" << '\n';

    l = 0;
    auto s2 = std::chrono::high_resolution_clock::now();
    for (auto &&i : big){ l += i.size(); }
    auto e2 = std::chrono::high_resolution_clock::now();
    auto d2 = std::chrono::duration_cast<std::chrono::nanoseconds>(e2 - s2);
    std::cout << l << " Time: " << d2.count() << "ns" << '\n';

}