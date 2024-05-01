#pragma once
#include "GoodType.h"
#include <array>

class Inventory
{
public:
	bool hasAtLeast(const GoodType& aGood, int aCount);
	void addGoods(const GoodType& aGood, int aCount);
	int numberOfGood(const GoodType& aGood);

	Inventory() {}
	Inventory(Inventory&) = delete;
	Inventory operator=(Inventory&) = delete;

private:
	std::array<int, Good::TYPES_COUNT> theInventory{};
};

