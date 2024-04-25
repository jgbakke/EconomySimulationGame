#pragma once
#include "GoodType.h"
#include <array>

class Inventory
{
public:
	bool hasAtLeast(GoodType aGood, int aCount);
	void addGoods(GoodType aGood, int aCount);
	int numberOfGood(GoodType aGood);

private:
	std::array<int, Good::TYPES_COUNT> theInventory{};
};

