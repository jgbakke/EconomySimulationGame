#include "GoodType.h"

GoodType::GoodType(std::string_view aDisplayName, int aId, GoodProductionCosts aProductionInputs) : theDisplayName(aDisplayName), theInventoryId(aId)
{
	int myTotalAmountOfResourcesToProduce = 0;

	for (auto& myProductionInput : aProductionInputs)
	{
		theInputResources[myProductionInput.first.theInventoryId] = myProductionInput.second;
		myTotalAmountOfResourcesToProduce += myProductionInput.second;
	}

	theProducingIsNetStorageIncrease = myTotalAmountOfResourcesToProduce == 0;
}

bool GoodType::producingIsNetStorageIncrease() const
{
	return theProducingIsNetStorageIncrease;
}

const GoodType::GoodsArray& GoodType::productionInputResources() const
{
	return theInputResources;
}