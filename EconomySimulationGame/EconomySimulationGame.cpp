#include <iostream>
#include "GoodType.h"
#include "Inventory.h"
#include "MatchingEngine.h"
#include "City.h"

static std::vector<Person> generateStartingCitizens()
{
	std::vector<Person> myTownStartingCitizens{};
	for (int myCitizen = 0; myCitizen < 100; myCitizen++)
	{
		Person& myNewPerson = myTownStartingCitizens.emplace_back("Person", 5 + (myCitizen / 10));
	}
	return myTownStartingCitizens;
}

static std::vector<Enterprise> generateStartingEnterprises(std::vector<Person>& aCitizens)
{
	std::vector<Enterprise> myStartingEnterprises{};
	myStartingEnterprises.emplace_back(Good::WOOD, aCitizens[20], 5);
	myStartingEnterprises.emplace_back(Good::WOOD, aCitizens[21], 40);
	myStartingEnterprises.emplace_back(Good::FOOD, aCitizens[22], 0);
	myStartingEnterprises.emplace_back(Good::FOOD, aCitizens[23], 10);
	myStartingEnterprises.emplace_back(Good::FOOD, aCitizens[24], 20);
	myStartingEnterprises.emplace_back(Good::BEER, aCitizens[25], 10);
	return myStartingEnterprises;
}

static void gameLoop()
{
	auto myStartingCitizens = generateStartingCitizens();
	auto myTownStartingEnterprises = generateStartingEnterprises(myStartingCitizens);

	City myMainCity{ "Nidaros", std::move(myStartingCitizens), std::move(myTownStartingEnterprises) };

	for (int myTurn = 0; myTurn < 300; myTurn++)
	{
		myMainCity.enterprisesProduceGoods();
		myMainCity.enterprisesBuyGoods();
		myMainCity.enterprisesSellGoods();
		myMainCity.personsBuyGoods();
		myMainCity.personsConsumeFood();
	}
}

void manualTest() {
	Inventory myBuyGuy;
	myBuyGuy.addGoods(Good::GOLD, 100);

	Inventory mySellGuy;
	mySellGuy.addGoods(Good::BEER, 2);

	std::cout << std::boolalpha;
	std::cout << "Can BuyGuy make food? " << Good::FOOD.canAffordToBeProduced(myBuyGuy.theInventory) << std::endl;
	std::cout << "Can SellGuy make food? " << Good::FOOD.canAffordToBeProduced(myBuyGuy.theInventory) << std::endl;;
	std::cout << "Can BuyGuy make beer? " << Good::BEER.canAffordToBeProduced(myBuyGuy.theInventory) << std::endl;;
	std::cout << "Can SellGuy make beer? " << Good::BEER.canAffordToBeProduced(myBuyGuy.theInventory) << std::endl;;

	std::cout << "Sell guy Beer: " << mySellGuy.numberOfGood(Good::BEER) << std::endl;
	std::cout << "Sell guy Money: " << mySellGuy.numberOfGood(Good::GOLD) << std::endl;

	std::cout << "Buy guy Beer: " << myBuyGuy.numberOfGood(Good::BEER) << std::endl;
	std::cout << "Buy guy Money: " << myBuyGuy.numberOfGood(Good::GOLD) << std::endl;

	MatchingEngine myMatchingEngine{ Good::BEER };
	myMatchingEngine.listItem(42, mySellGuy);
	myMatchingEngine.listItem(60, mySellGuy);

	std::cout << "Listed for sale" << std::endl;
	std::cout << "Sell guy Beer: " << mySellGuy.numberOfGood(Good::BEER) << std::endl;
	std::cout << "Sell guy Money: " << mySellGuy.numberOfGood(Good::GOLD) << std::endl;

	std::cout << "Buy guy Beer: " << myBuyGuy.numberOfGood(Good::BEER) << std::endl;
	std::cout << "Buy guy Money: " << myBuyGuy.numberOfGood(Good::GOLD) << std::endl;

	std::cout << "Can he purchase? " << myMatchingEngine.purchase(myBuyGuy) << std::endl;
	std::cout << "Sell guy Beer: " << mySellGuy.numberOfGood(Good::BEER) << std::endl;
	std::cout << "Sell guy Money: " << mySellGuy.numberOfGood(Good::GOLD) << std::endl;

	std::cout << "Buy guy Beer: " << myBuyGuy.numberOfGood(Good::BEER) << std::endl;
	std::cout << "Buy guy Money: " << myBuyGuy.numberOfGood(Good::GOLD) << std::endl;


	std::cout << "Can he purchase? " << myMatchingEngine.purchase(myBuyGuy) << std::endl;
	std::cout << "Sell guy Beer: " << mySellGuy.numberOfGood(Good::BEER) << std::endl;
	std::cout << "Sell guy Money: " << mySellGuy.numberOfGood(Good::GOLD) << std::endl;

	std::cout << "Buy guy Beer: " << myBuyGuy.numberOfGood(Good::BEER) << std::endl;
	std::cout << "Buy guy Money: " << myBuyGuy.numberOfGood(Good::GOLD) << std::endl;

	std::cout << "Can BuyGuy make food? " << Good::FOOD.canAffordToBeProduced(myBuyGuy.theInventory) << std::endl;
	std::cout << "Can SellGuy make food? " << Good::FOOD.canAffordToBeProduced(myBuyGuy.theInventory) << std::endl;;
	std::cout << "Can BuyGuy make beer? " << Good::BEER.canAffordToBeProduced(myBuyGuy.theInventory) << std::endl;;
	std::cout << "Can SellGuy make beer? " << Good::BEER.canAffordToBeProduced(myBuyGuy.theInventory) << std::endl;;

	myBuyGuy.addGoods(Good::FOOD, 1);
	std::cout << "Can BuyGuy make beer? " << Good::BEER.canAffordToBeProduced(myBuyGuy.theInventory) << std::endl;;
	std::cout << "He still needs more food: " << Good::BEER.additionalResourcesNeededToProduce(myBuyGuy.theInventory)[Good::FOOD.theInventoryId] << std::endl;

	myBuyGuy.addGoods(Good::FOOD, 1);
	std::cout << "Can BuyGuy make beer? " << Good::BEER.canAffordToBeProduced(myBuyGuy.theInventory) << std::endl;;
	std::cout << "He still needs more food: " << Good::BEER.additionalResourcesNeededToProduce(myBuyGuy.theInventory)[Good::FOOD.theInventoryId] << std::endl;
}

int main()
{
	manualTest();
}