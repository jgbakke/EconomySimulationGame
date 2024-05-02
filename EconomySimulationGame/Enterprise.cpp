#include "Enterprise.h"

void Enterprise::produceGoods()
{
	if (!theInventory.canAffordToProduce(theGoodType) || (theInventory.isAtStorageCapacity() && theGoodType.producingIsNetStorageIncrease()))
	{
		return;
	}
}
