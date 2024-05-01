#pragma once
#include <string>
#include <string_view>
#include <vector>
#include <array>

namespace Good
{
	constexpr static int TYPES_COUNT = 4;
}

class GoodType
{
public:
	using GoodProductionCosts = std::initializer_list <std::pair <const GoodType&, int>>;
	using GoodsArray = std::array<int, Good::TYPES_COUNT>;

	GoodType(std::string_view aDisplayName, int aId, GoodProductionCosts aProductionInputs);
	const std::string_view theDisplayName;
	const int theInventoryId;

	GoodType(GoodType&) = delete;
	GoodType operator=(GoodType&) = delete;

	bool canAffordToBeProduced(const GoodType::GoodsArray& aProducerInventory);
	GoodsArray additionalResourcesNeededToProduce(const GoodType::GoodsArray& aProducerInventory);

private:
	GoodsArray theInputResources{};
};

namespace Good
{
	// probably want a test to validate that all IDs are sequential and non-duplicates, and that types count is right
	static GoodType GOLD{ "Gold", 0, {} };
	static GoodType WOOD{ "Wood", 1, {} };
	static GoodType FOOD{ "Food", 2, {} };
	static GoodType BEER{ "Beer", 3, {{Good::FOOD, 2}} };
}