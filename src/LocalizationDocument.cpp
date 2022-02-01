#include "LocalizationDocument.hpp"
using namespace Diglett;

#include "main.hpp"

#include "Polyglot/Localization.hpp"

LocalizationDocument *LocalizationDocument::EN = new LocalizationDocument();
LocalizationDocument *LocalizationDocument::FR = new LocalizationDocument();
LocalizationDocument *LocalizationDocument::ES = new LocalizationDocument();
LocalizationDocument *LocalizationDocument::DE = new LocalizationDocument();
LocalizationDocument *LocalizationDocument::JA = new LocalizationDocument();
LocalizationDocument *LocalizationDocument::KO = new LocalizationDocument();

std::map<std::string, LocalizationDocument *> LocalizationDocument::customLocalizationDocuments = std::map<std::string, LocalizationDocument *>();

void LocalizationDocument::AddLocalizations(std::map<std::string, std::u16string> map) {
    translations.merge(map);

    for (const auto& pair : map) {
        getLogger().info("Registered key %s with value %s", pair.first.c_str(), to_utf8(pair.second).c_str());
    }
}

LocalizationDocument *LocalizationDocument::GetEN() { return EN; }

LocalizationDocument *LocalizationDocument::GetFR() { return FR; }

LocalizationDocument *LocalizationDocument::GetES() { return ES; }

LocalizationDocument *LocalizationDocument::GetDE() { return DE; }

LocalizationDocument *LocalizationDocument::GetJA() { return JA; }

LocalizationDocument *LocalizationDocument::GetKO() { return KO; }

LocalizationDocument::LocalizationDocument() {
    translations = std::map<std::string, std::u16string>();
}

std::u16string LocalizationDocument::Get(const std::string& key) {
    if (!translations[key].empty()) return translations.find(key)->second;
    else return to_utf16(key);
}

LocalizationDocument *LocalizationDocument::GetCustom(const std::string& name) {
    if (customLocalizationDocuments.find(name) == customLocalizationDocuments.end())
        customLocalizationDocuments.insert(std::pair<std::string, LocalizationDocument *>(name, new LocalizationDocument()));

    return customLocalizationDocuments[name];
}

LocalizationDocument *LocalizationDocument::GetSelected() {
    Polyglot::Language selectedLanguage = Polyglot::Localization::get_Instance()->get_SelectedLanguage();
    auto selected = (Languages) selectedLanguage.value;

    switch (selected) {
        case Languages::French:
            return GetFR();
        case Languages::Spanish:
            return GetES();
        case Languages::German:
            return GetDE();
        case Languages::Japanese:
            return GetJA();
        case Languages::Korean:
            return GetKO();
        case Languages::English:
        default:
            return GetEN();

    }
}