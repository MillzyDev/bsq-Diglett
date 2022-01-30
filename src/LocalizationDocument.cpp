#include "LocalizationDocument.hpp"
using namespace Diglett;

#include "main.hpp"

LocalizationDocument *LocalizationDocument::EN = new LocalizationDocument();
LocalizationDocument *LocalizationDocument::FR = new LocalizationDocument();
LocalizationDocument *LocalizationDocument::ES = new LocalizationDocument();
LocalizationDocument *LocalizationDocument::DE = new LocalizationDocument();
LocalizationDocument *LocalizationDocument::JA = new LocalizationDocument();
LocalizationDocument *LocalizationDocument::KO = new LocalizationDocument();

void LocalizationDocument::AddLocalizations(std::vector<std::pair<std::string, std::string>> map) {

    std::vector<std::pair<std::string, std::string>> combined = translations;
    combined.reserve(translations.size() + map.size());
    combined.insert(combined.end(), translations.begin(), translations.end());
    combined.insert(combined.end(), map.begin(), map.end());
    translations = combined;

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
    translations = std::vector<std::pair<std::string, std::string>>();
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
