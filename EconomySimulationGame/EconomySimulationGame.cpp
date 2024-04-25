#include <iostream>
#include "GoodType.h"

int main()
{
    std::cout << Good::GOLD.theDisplayName << std::endl;
    std::cout << Good::WOOD.theDisplayName << std::endl;
    std::cout << Good::FOOD.theDisplayName << std::endl;
    std::cout << Good::BEER.theDisplayName << std::endl;
}