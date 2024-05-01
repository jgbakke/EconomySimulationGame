#include "MatchingEngine.h"

void MatchingEngine::listItem(int aPrice, Inventory& aSeller)
{
	theOffersPerPriceLevel.insert({ aPrice, aSeller });
	aSeller.addGoods(theGoodType, -1);
}

bool MatchingEngine::purchase(Inventory& aPurchaser)
{
	auto myBestPriceOptional = getBestPrice();
	if (!myBestPriceOptional.has_value())
	{
		return false;
	}

	int myBestPrice = *myBestPriceOptional;

	if (!aPurchaser.hasAtLeast(Good::GOLD, myBestPrice))
	{
		return false;
	}

	aPurchaser.addGoods(theGoodType, 1);
	aPurchaser.addGoods(Good::GOLD, -myBestPrice);

	Inventory& mySeller = theOffersPerPriceLevel.begin()->second;
	mySeller.addGoods(Good::GOLD, myBestPrice);
	theOffersPerPriceLevel.erase(theOffersPerPriceLevel.begin());
	return true;
}

std::optional<int> MatchingEngine::getBestPrice()
{
	if (theOffersPerPriceLevel.empty())
	{
		return std::nullopt;
	}

	return theOffersPerPriceLevel.begin()->first;
}
