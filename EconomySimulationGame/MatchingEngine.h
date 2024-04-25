#pragma once
#include <map>
#include "Enterprise.h"
#include "Inventory.h"

// A matching engine is a per-good object that stores all sellers and prices
// For purposes of game mechanics, the matching engine only needs to have Offers
class MatchingEngine
{
public:
	void listItem(int aPrice, Enterprise& aSeller);

	void purchase(Inventory& aPurchaser);

private:
	std::multimap<int, Enterprise&> theOffersPerPriceLevel{}; // Ask price in gold mapped to each Enterprise that has an offer
};

