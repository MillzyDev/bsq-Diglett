#include "LocalizationDocument.hpp"
#include "Parsing.hpp"
using namespace Diglett;

std::string LocalizationDocument::operator[](std::string key) {
    return translations[key];
}

void LocalizationDocument::AddLocalizations(std::map<std::string, std::string> map) {
    translations.merge(map);
}

LocalizationDocument *LocalizationDocument::GetEN() { return EN; }

LocalizationDocument *LocalizationDocument::GetFR() { return FR; }

LocalizationDocument *LocalizationDocument::GetES() { return ES; }

LocalizationDocument *LocalizationDocument::GetDE() { return DE; }

LocalizationDocument *LocalizationDocument::GetJA() { return JA; }

LocalizationDocument *LocalizationDocument::GetKO() { return KO; }