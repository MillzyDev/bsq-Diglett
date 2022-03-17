#pragma once

#include "LocalizationAsset.hpp"
#include "Language.hpp"

namespace Diglett {
    /** @file Register.hpp
     * Registers a LocalizationAsset
     * @param asset The localization asset (can be implicitly converted from std::string_view
     * @param language The language of the Localization asset
     */
    void RegisterAsset(LocalizationAsset asset, Language language);
}