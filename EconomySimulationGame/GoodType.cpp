#include "GoodType.h"
#include <algorithm>
#include <iterator>

GoodType::GoodType(std::string_view aDisplayName, int aId, GoodProductionCosts aProductionInputs) : theDisplayName(aDisplayName), theInventoryId(aId)
{
	for (auto& myProductionInput : aProductionInputs)
	{
		theInputResources[myProductionInput.first.theInventoryId] = myProductionInput.second;
	}
}

bool GoodType::canAffordToBeProduced(const GoodType::GoodsArray& aProducerInventory)
{
	auto myAdditionalNeeded = additionalResourcesNeededToProduce(aProducerInventory);
	return !std::any_of(myAdditionalNeeded.begin(), myAdditionalNeeded.end(), [](const int& aAdditionalNeeded) {return aAdditionalNeeded > 0; });
}

GoodType::GoodsArray GoodType::additionalResourcesNeededToProduce(const GoodType::GoodsArray& aProducerInventory)
{
	GoodType::GoodsArray myAdditionalResourcesNeeded{};
	std::transform(theInputResources.begin(), theInputResources.end(),
		aProducerInventory.begin(),
		myAdditionalResourcesNeeded.begin(),
		[](const int& aRequired, const int& aHasCount) { return std::max(aRequired - aHasCount, 0); });

	return myAdditionalResourcesNeeded;
}
