#include "Enterprise.h"
#include <iostream>

void Enterprise::produceGoods(int aCurrentTime)
{
	if (aCurrentTime % theGoodType.defaultTimeToProduce() != 0)
	{
		return;
	}

	if (!theInventory.canAffordToProduce(theGoodType) || (theInventory.isAtStorageCapacity() && theGoodType.producingIsNetStorageIncrease()))
	{
		return;
	}

	theInventory -= theGoodType.productionInputResources();
	theInventory.addGoods(theGoodType, 1);
	std::cout << static_cast<void*>(this) << " produced " << theGoodType.theDisplayName << " at " << aCurrentTime << std::endl;
}
