#include "util/string_util.h"

namespace string_util
{

bool IEqualStrings(const char* const str1, const char* const str2)
{
	const auto str1Size = std::strlen(str1);
	return ((str1Size == std::strlen(str2)) && std::equal(str1, str1 + str1Size, str2, [](auto& c1, auto& c2) {
		return (c1 == c2) || (std::toupper(c1) == std::toupper(c2)) || (std::towupper(c1) == std::towupper(c2));
	}));
}

} // namespace string_util
