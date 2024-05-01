#pragma once
#include "GoodType.h"
#include "Person.h"

// An Enterprise is an in-game term referring to a business that produces goods
class Enterprise
{
public:
	Enterprise(const GoodType& aGoodType, Person& aOwner, int aStartingGold) : theGoodType(aGoodType), theOwner(aOwner), theInventory{} {
		theInventory.addGoods(Good::GOLD, aStartingGold);
	}

private:
	const GoodType& theGoodType;
	Person& theOwner;
	Inventory theInventory;
};

