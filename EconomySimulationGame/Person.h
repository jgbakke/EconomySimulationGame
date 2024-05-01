#pragma once
#include "Inventory.h"

class Person
{
public:
	Person(std::string aName, int aStartingGold) : theName(aName), theInventory{} {
		theInventory.addGoods(Good::GOLD, aStartingGold);
	}

private:
	const std::string theName;
	Inventory theInventory;
};

