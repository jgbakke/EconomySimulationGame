#include "Inventory.h"

Inventory::Inventory(std::initializer_list<std::pair<const GoodType&, int>> aStartingGoods)
{
    for (auto myStartingGood : aStartingGoods)
    {
        addGoods(myStartingGood.first, myStartingGood.second);
    }
}

bool Inventory::hasAtLeast(const GoodType& aGood, int aCount)
{
    return hasAtLeast(aGood.theInventoryId, aCount);
}

bool Inventory::hasAtLeast(int aGoodId, int aCount)
{
    return theInventory[aGoodId] >= aCount;
}

void Inventory::addGoods(const GoodType& aGood, int aCount)
{
    theInventory[aGood.theInventoryId] += aCount;
}

int Inventory::numberOfGood(const GoodType& aGood)
{
    return theInventory[aGood.theInventoryId];
}
