#include "GoodType.h"

GoodType::GoodType(std::string_view aDisplayName, int aId, GoodProductionCosts aProductionInputs, int aTimeToProduce) : 
	theDisplayName(aDisplayName), theInventoryId(aId), theTimeToProduce(aTimeToProduce)
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

int GoodType::defaultTimeToProduce() const
{
	return theTimeToProduce;
}
