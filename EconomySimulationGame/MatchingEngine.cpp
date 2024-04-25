#include "MatchingEngine.h"

void MatchingEngine::listItem(int aPrice, Enterprise& aSeller)
{
	theOffersPerPriceLevel.insert({ aPrice, aSeller });
}