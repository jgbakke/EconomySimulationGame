#include "Inventory.h"

bool Inventory::hasAtLeast(GoodType aGood, int aCount)
{
    return numberOfGood(aGood) >= aCount;
}

void Inventory::addGoods(GoodType aGood, int aCount)
{
    theInventory[aGood.theInventoryId] += aCount;
}

int Inventory::numberOfGood(GoodType aGood)
{
    return theInventory[aGood.theInventoryId];
}
