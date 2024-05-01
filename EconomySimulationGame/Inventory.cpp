#include "Inventory.h"

bool Inventory::hasAtLeast(const GoodType& aGood, int aCount)
{
    return numberOfGood(aGood) >= aCount;
}

void Inventory::addGoods(const GoodType& aGood, int aCount)
{
    theInventory[aGood.theInventoryId] += aCount;
}

int Inventory::numberOfGood(const GoodType& aGood)
{
    return theInventory[aGood.theInventoryId];
}
