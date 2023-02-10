#include "CardPool.h"

#include <iostream>

using namespace herokill;

int main(void)
{
    std::cout << "hello herokill" << std::endl;
    std::cout << "card pool init:" << std::endl;
    CardPool pools;
    pools.dumpCards();
    std::cout << "card pool shuffle:" << std::endl;
    pools.shuffle();
    pools.dumpCards();

    return 0;
}
