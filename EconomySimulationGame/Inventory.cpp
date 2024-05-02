#include "Inventory.h"
#include <algorithm>

Inventory::Inventory(std::initializer_list<std::pair<const GoodType&, int>> aStartingGoods)
{
    for (auto myStartingGood : aStartingGoods)
    {
        addGoods(myStartingGood.first, myStartingGood.second);
    }
}

Inventory Inventory::operator-(const GoodType::GoodsArray& aOther) const
{
    Inventory myDifferenceInventory{};
    std::transform(theInventory.begin(), theInventory.end(),
        aOther.begin(),
        myDifferenceInventory.theInventory.begin(),
        [](const int& aThisAmount, const int& aOtherAmount) { return aThisAmount - aOtherAmount; });

    return myDifferenceInventory;
}

void Inventory::operator-=(const GoodType::GoodsArray& aOther)
{
    Inventory mySubtractedInventory = *this - aOther;
    theInventory = mySubtractedInventory.theInventory;
}

Inventory Inventory::operator-(const Inventory& aOther) const
{
    return *this - aOther.theInventory;
}

bool Inventory::hasAtLeast(const GoodType& aGood, int aCount) const
{
    return hasAtLeast(aGood.theInventoryId, aCount);
}

bool Inventory::hasAtLeast(int aGoodId, int aCount) const
{
    return theInventory[aGoodId] >= aCount;
}

void Inventory::addGoods(const GoodType& aGood, int aCount)
{
    theInventory[aGood.theInventoryId] += aCount;

    if (aGood.theInventoryId != Good::GOLD.theInventoryId)
    {
        theStoredResourcesCount += aCount;
    }
}

int Inventory::numberOfGood(const GoodType& aGood) const
{
    return theInventory[aGood.theInventoryId];
}

bool Inventory::isAtStorageCapacity() const
{
    return theStoredResourcesCount >= STORAGE_CAPACITY;
}

bool Inventory::canAffordToProduce(const GoodType& aGood) const
{
    auto myExcessResources = excessResourcesForProduction(aGood);
    return std::all_of(myExcessResources.begin(), myExcessResources.end(), [](const int& aExcessCount) {return aExcessCount >= 0; });
}

GoodType::GoodsArray Inventory::excessResourcesForProduction(const GoodType& aGood) const
{
    Inventory myExcessInventory = *this - aGood.productionInputResources();
    return myExcessInventory.theInventory;
}
