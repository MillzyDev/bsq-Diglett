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

void LocalizationDocument::AddLocalizations(std::map<std::string, std::string> map) {
    translations.merge(map);

    for (const auto& pair : map) {
        getLogger().info("Registered key %s with value %s", pair.first.c_str(), pair.second.c_str());
    }
}

LocalizationDocument *LocalizationDocument::GetEN() { return EN; }

LocalizationDocument *LocalizationDocument::GetFR() { return FR; }

LocalizationDocument *LocalizationDocument::GetES() { return ES; }

LocalizationDocument *LocalizationDocument::GetDE() { return DE; }

LocalizationDocument *LocalizationDocument::GetJA() { return JA; }

LocalizationDocument *LocalizationDocument::GetKO() { return KO; }

LocalizationDocument::LocalizationDocument() {
    translations = std::map<std::string, std::string>();
}

std::string LocalizationDocument::Get(const std::string& key) {
    std::string first = std::string();
    std::string second = std::string();
    for (auto & translation : translations) {
        getLogger().info("Checking key %s", translation.first.c_str());
        if (translation.first == key) {
            first = translation.first;
            second = translation.second;
        }
    }
    if (first.empty() && second.empty()) return key;
    else return second;
}

LocalizationDocument *LocalizationDocument::GetCustom(std::string name) {
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
