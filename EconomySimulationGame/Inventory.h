#pragma once
#include <array>
#include "GoodType.h"

class Inventory
{
public:
	Inventory(std::initializer_list<std::pair<const GoodType&, int>> aStartingGoods);
	Inventory() : theInventory{} {}

	bool hasAtLeast(const GoodType& aGood, int aCount);
	bool hasAtLeast(int aGoodId, int aCount);
	void addGoods(const GoodType& aGood, int aCount);
	int numberOfGood(const GoodType& aGood);

private:
	GoodType::GoodsArray theInventory;
};

