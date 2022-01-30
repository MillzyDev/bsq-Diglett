#include "LocalizationDocument.hpp"
using namespace Diglett;

#include "main.hpp"

LocalizationDocument LocalizationDocument::EN = LocalizationDocument();
LocalizationDocument LocalizationDocument::FR = LocalizationDocument();
LocalizationDocument LocalizationDocument::ES = LocalizationDocument();
LocalizationDocument LocalizationDocument::DE = LocalizationDocument();
LocalizationDocument LocalizationDocument::JA = LocalizationDocument();
LocalizationDocument LocalizationDocument::KO = LocalizationDocument();

void LocalizationDocument::AddLocalizations(std::map<std::string, std::string> map) {
    translations.merge(map);
    for (const auto& pair : map) {
        getLogger().info("Registered key %s with value %s", pair.first.c_str(), pair.second.c_str());
    }
}

LocalizationDocument LocalizationDocument::GetEN() { return EN; }

LocalizationDocument LocalizationDocument::GetFR() { return FR; }

LocalizationDocument LocalizationDocument::GetES() { return ES; }

LocalizationDocument LocalizationDocument::GetDE() { return DE; }

LocalizationDocument LocalizationDocument::GetJA() { return JA; }

LocalizationDocument LocalizationDocument::GetKO() { return KO; }

LocalizationDocument::LocalizationDocument() {
    translations = std::map<std::string, std::string>();

}

std::string LocalizationDocument::Get(std::string key) {
    return translations.find(key)->second;
}
