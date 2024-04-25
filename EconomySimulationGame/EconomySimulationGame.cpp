#include <iostream>
#include "GoodType.h"
#include "Inventory.h"
#include "MatchingEngine.h"

int main()
{
    Inventory myBuyGuy;
    myBuyGuy.addGoods(Good::GOLD, 100);

    Inventory mySellGuy;
    mySellGuy.addGoods(Good::BEER, 2);

    std::cout << "Sell guy Beer: " << mySellGuy.numberOfGood(Good::BEER) << std::endl;
    std::cout << "Sell guy Money: " << mySellGuy.numberOfGood(Good::GOLD) << std::endl;

    std::cout << "Buy guy Beer: " << myBuyGuy.numberOfGood(Good::BEER) << std::endl;
    std::cout << "Buy guy Money: " << myBuyGuy.numberOfGood(Good::GOLD) << std::endl;

    MatchingEngine myMatchingEngine{ Good::BEER };
    myMatchingEngine.listItem(42, mySellGuy);
    myMatchingEngine.listItem(60, mySellGuy);

    std::cout << "Listed for sale" << std::endl;
    std::cout << "Sell guy Beer: " << mySellGuy.numberOfGood(Good::BEER) << std::endl;
    std::cout << "Sell guy Money: " << mySellGuy.numberOfGood(Good::GOLD) << std::endl;

    std::cout << "Buy guy Beer: " << myBuyGuy.numberOfGood(Good::BEER) << std::endl;
    std::cout << "Buy guy Money: " << myBuyGuy.numberOfGood(Good::GOLD) << std::endl;

    std::cout << "Can he purchase? " << std::boolalpha << myMatchingEngine.purchase(myBuyGuy) << std::endl;
    std::cout << "Sell guy Beer: " << mySellGuy.numberOfGood(Good::BEER) << std::endl;
    std::cout << "Sell guy Money: " << mySellGuy.numberOfGood(Good::GOLD) << std::endl;

    std::cout << "Buy guy Beer: " << myBuyGuy.numberOfGood(Good::BEER) << std::endl;
    std::cout << "Buy guy Money: " << myBuyGuy.numberOfGood(Good::GOLD) << std::endl;


    std::cout << "Can he purchase? " << myMatchingEngine.purchase(myBuyGuy) << std::endl;
    std::cout << "Sell guy Beer: " << mySellGuy.numberOfGood(Good::BEER) << std::endl;
    std::cout << "Sell guy Money: " << mySellGuy.numberOfGood(Good::GOLD) << std::endl;

    std::cout << "Buy guy Beer: " << myBuyGuy.numberOfGood(Good::BEER) << std::endl;
    std::cout << "Buy guy Money: " << myBuyGuy.numberOfGood(Good::GOLD) << std::endl;

}