#include "Enterprise.h"
#include <iostream>

void Enterprise::produceGoods(int aCurrentTime)
{
	if (!theInventory.canAffordToProduce(theGoodType) || (theInventory.isAtStorageCapacity() && theGoodType.producingIsNetStorageIncrease()))
	{
		return;
	}

	if ((aCurrentTime - theLastProducedAtTime) < theGoodType.defaultTimeToProduce())
	{
		return;
	}

	theInventory -= theGoodType.productionInputResources();
	theInventory.addGoods(theGoodType, 1);
	theLastProducedAtTime = aCurrentTime;
	std::cout << static_cast<void*>(this) << " produced " << theGoodType.theDisplayName << " at " << aCurrentTime << std::endl;
}
