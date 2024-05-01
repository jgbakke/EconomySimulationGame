#pragma once
#include <string>
#include <vector>
#include "Person.h"
#include "Enterprise.h"
#include "Marketplace.h"

class City
{
public:
	City(std::string aName, std::vector<Person>&& aPersons, std::vector<Enterprise>&& aEnterprises) :
		theName(aName), thePersons(aPersons), theEnterprises(aEnterprises), theMarketplace() {}

	void enterprisesProduceGoods();
	void enterprisesBuyGoods();
	void enterprisesSellGoods();
	void personsBuyGoods();
	void personsConsumeFood();

private:
	const std::string theName;
	std::vector<Person> thePersons;
	std::vector<Enterprise> theEnterprises;
	const Marketplace theMarketplace;
};

