#include "Localization.hpp"
#include "Util.hpp"
#include "main.hpp"

Diglett::Localization *Diglett::Localization::s_instance;

Diglett::Localization::Localization() = default;

Diglett::Localization *Diglett::Localization::get_instance() {
    if (s_instance == nullptr)
        s_instance = new Localization();
    return s_instance;
}

LocalizationDocument &Diglett::Localization::get_document() {
    return document;
}

LocalizationMap &Diglett::Localization::getLocales(Diglett::Language language) {
    if (get_document().find(language) == get_document().end()) {
        getLogger().info("Emplacing new document entry...");
        get_document().emplace(language, LocalizationMap());
    }
    getLogger().info("Got document entry!");
    return get_document().find(language)->second;
}

StringW Diglett::Localization::get(const std::string& key, Diglett::Language language) {
    auto& locale = getLocales(language);
    auto itr = locale.find(key);
    if (itr == locale.end())
    {
        return key;
    }
    return {itr->second};
}

StringW Diglett::Localization::get(const std::string& key) {
    return get(key, Diglett::getSelectedLanguage());
}

