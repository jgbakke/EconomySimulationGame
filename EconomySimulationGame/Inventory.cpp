#include "Inventory.h"
#include <algorithm>

Inventory::Inventory(std::initializer_list<std::pair<const GoodType&, int>> aStartingGoods)
{
    for (auto myStartingGood : aStartingGoods)
    {
        addGoods(myStartingGood.first, myStartingGood.second);
    }
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

    if (&aGood != &Good::GOLD)
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
    auto myAdditionalNeeded = additionalResourcesNeededToProduce(aGood);
    return !std::any_of(myAdditionalNeeded.begin(), myAdditionalNeeded.end(), [](const int& aAdditionalNeeded) {return aAdditionalNeeded > 0; });
}

GoodType::GoodsArray Inventory::additionalResourcesNeededToProduce(const GoodType& aGood) const
{
    GoodType::GoodsArray myAdditionalResourcesNeeded{};
    std::transform(theInventory.begin(), theInventory.end(),
        aGood.productionInputResources().begin(),
        myAdditionalResourcesNeeded.begin(),
        [](const int& aHasAmount, const int& aRequiredAmount) { return std::max(aRequiredAmount - aHasAmount, 0); });

    return myAdditionalResourcesNeeded;
}
