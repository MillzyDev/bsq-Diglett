#include "Register.hpp"
#include "Localization.hpp"

#include "main.hpp"

void Diglett::RegisterAsset(Diglett::LocalizationAsset asset, Diglett::Language language) {
    auto localization = Localization::get_instance();
    auto localizations = asset.get_localizations();
    getLogger().info("Inserting Locales");
    localization->getLocales(language).insert(localizations.begin(), localizations.end());
}
