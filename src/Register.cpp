#include "Register.hpp"
#include "Localization.hpp"

#include "main.hpp"

void Diglett::RegisterAsset(Diglett::LocalizationAsset asset, Diglett::Language language) {
    auto localization = Localization::get_instance();
    auto localizations = asset.get_localizations();
    auto &locales = localization->getLocales(language);
    for (const auto& p : localizations) {
        locales.insert(p);
        getLogger().info("Registered %s - %s", p.first.c_str(), p.second.data());
    }
}
