#pragma once
#include <map>
#include <optional>
#include "Inventory.h"

// A matching engine is a per-good object that stores all sellers and prices
// For purposes of game mechanics, the matching engine only needs to have Offers
class MatchingEngine
{
public:
	MatchingEngine(GoodType aGoodType) : theGoodType(aGoodType) {}

	void listItem(int aPrice, Inventory& aSeller);
	bool purchase(Inventory& aPurchaser);
	std::optional<int> getBestPrice();

private:
	const GoodType& theGoodType;
	std::multimap<int, Inventory&> theOffersPerPriceLevel{}; // Ask price in gold mapped to each enterprise's Inventory that has an offer
};

