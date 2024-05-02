#include "City.h"

void City::enterprisesProduceGoods(int aCurrentTime)
{
	for (auto& myEnterprise : theEnterprises)
	{
		myEnterprise.produceGoods(aCurrentTime);
	}
}

void City::enterprisesBuyGoods()
{
}

void City::enterprisesSellGoods()
{
}

void City::personsBuyGoods()
{
}

void City::personsConsumeFood()
{
}
