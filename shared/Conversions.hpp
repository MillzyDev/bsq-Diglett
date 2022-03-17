#pragma once

#include <string_view>

/** @file Conversions.hpp
 * Converts a binary asset data structure to an std::string_view
 */
#define ASSET_TO_STR(asset) std::string_view(reinterpret_cast<char *>(asset::getData()), asset::getLength())