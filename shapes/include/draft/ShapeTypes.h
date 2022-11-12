#pragma once

#include "util/string_util.h"
#include <istream>
#include <string_view>

namespace draft
{

enum class ShapeType
{
	CIRCLE,
	TRIANGLE,
	RECTANGLE,
	UNKNOWN
};

namespace shape_string_types
{

constexpr std::string_view CIRCLE = "circle";
constexpr std::string_view TRIANGLE = "triangle";
constexpr std::string_view RECTANGLE = "rectangle";
constexpr std::string_view UNKNOWN = "unknown";

} // namespace shape_type_str

template <typename StringT>
static inline ShapeType StringToColor(StringT&& str)
{
	using namespace shape_string_types;
	using namespace string_util;

	if (IEqualStrings(str, CIRCLE))
	{
		return ShapeType::CIRCLE;
	}
	else if (IEqualStrings(str, TRIANGLE))
	{
		return ShapeType::TRIANGLE;
	}
	else if (IEqualStrings(str, RECTANGLE))
	{
		return ShapeType::RECTANGLE;
	}
	return ShapeType::UNKNOWN;
}

static inline std::istream& operator>>(std::istream& lhs, ShapeType& rhs)
{
	if (!std::istream::sentry(lhs))
	{
		return lhs;
	}

	std::string src;
	lhs >> src;

	auto res = StringToColor(std::move(src));
	if (res == ShapeType::UNKNOWN)
	{
		lhs.setstate(std::ios_base::failbit);
		return lhs;
	}
	rhs = res;

	return lhs;
}

} // namespace draft
