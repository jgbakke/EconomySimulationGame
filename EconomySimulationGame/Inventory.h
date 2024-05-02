#pragma once
#include <array>
#include "GoodType.h"

class Inventory
{
public:
	Inventory(std::initializer_list<std::pair<const GoodType&, int>> aStartingGoods);
	Inventory() = default;
	Inventory operator-(const GoodType::GoodsArray& aOther) const;
	void operator-=(const GoodType::GoodsArray& aOther);
	Inventory operator-(const Inventory& aOther) const;

	bool hasAtLeast(const GoodType& aGood, int aCount) const;
	bool hasAtLeast(int aGoodId, int aCount) const;
	void addGoods(const GoodType& aGood, int aCount);
	int numberOfGood(const GoodType& aGood) const;
	bool isAtStorageCapacity() const;
	bool canAffordToProduce(const GoodType& aGood) const;
	GoodType::GoodsArray excessResourcesForProduction(const GoodType& aGood) const;

private:
	int theStoredResourcesCount = 0;
	GoodType::GoodsArray theInventory{};
	constexpr static int STORAGE_CAPACITY = 10;
};

