#pragma once

#include <cstring>
#include <cwctype>
#include <string>

namespace string_util
{

template <typename StringSource, typename StringTest>
static inline bool IEqualStrings(StringSource&& str1, StringTest&& str2)
{
	return ((str1.size() == str2.size()) && std::equal(str1.begin(), str1.end(), str2.begin(), [](auto& c1, auto& c2) {
		return (c1 == c2) || (std::toupper(c1) == std::toupper(c2)) || (std::towupper(c1) == std::towupper(c2));
	}));
}

template <typename StringSource>
static inline bool IEqualStrings(StringSource&& str1, const char* const str2)
{
	return ((str1.size() == std::strlen(str2)) && std::equal(str1.begin(), str1.end(), str2, [](auto& c1, auto& c2) {
		return (c1 == c2) || (std::toupper(c1) == std::toupper(c2)) || (std::towupper(c1) == std::towupper(c2));
	}));
}

template <typename StringTest>
static inline bool IEqualStrings(const char* const str1, StringTest&& str2)
{
	return ((std::strlen(str1) == str2.size()) && std::equal(str2.begin(), str2.end(), str1, [](auto& c1, auto& c2) {
		return (c1 == c2) || (std::toupper(c1) == std::toupper(c2)) || (std::towupper(c1) == std::towupper(c2));
	}));
}

bool IEqualStrings(const char* const str1, const char* const str2);

} // namespace string_util
