#pragma once
#include <string>
#include <string_view>

class GoodType
{
public:
	constexpr GoodType(std::string_view aDisplayName, int aId) : theDisplayName(aDisplayName), theInventoryId(aId) {}
	const std::string_view theDisplayName;
	const int theInventoryId;
};

namespace Good
{
	// probably want a test to validate that all IDs are sequential and non-duplicates, and that types count is right
	constexpr static GoodType GOLD{ "Gold", 0 };
	constexpr static GoodType WOOD{ "Wood", 1 };
	constexpr static GoodType FOOD{ "Food", 2 };
	constexpr static GoodType BEER{ "Beer", 3 };
	constexpr static int TYPES_COUNT = 4;
}