#include <iostream>
#include "cpr/cpr.h"

int main(int argc, char const *argv[])
{
    auto r = cpr::Get(cpr::Url{"Example.com"});
    std::cout << r.text << '\n';
}


