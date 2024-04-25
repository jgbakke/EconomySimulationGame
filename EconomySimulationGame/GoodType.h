#pragma once
#include <string>
#include <string_view>

class GoodType
{
public:
	constexpr GoodType(std::string_view aDisplayName) : theDisplayName(aDisplayName) {}
	const std::string_view theDisplayName;
};

namespace Good
{
	constexpr static GoodType GOLD{ "Gold" };
	constexpr static GoodType WOOD{ "Wood" };
	constexpr static GoodType FOOD{ "Food" };
	constexpr static GoodType BEER{ "Beer" };
}