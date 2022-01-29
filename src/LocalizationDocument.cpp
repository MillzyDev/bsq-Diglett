#include "LocalizationDocument.hpp"
#include "Parsing.hpp"
using namespace Diglett;

std::string LocalizationDocument::operator[](std::string key) {
    return translations[key];
}

template<Format F>
void LocalizationDocument::AddLocalizations(std::string fileContent) {
    switch (F) {
        case Format::JSON:
            auto parsed = Parsing::ParseJson(fileContent);
            translations.merge(parsed);
    }
}

LocalizationDocument *LocalizationDocument::GetEN() { return EN; }

LocalizationDocument *LocalizationDocument::GetFR() { return FR; }

LocalizationDocument *LocalizationDocument::GetES() { return ES; }

LocalizationDocument *LocalizationDocument::GetDE() { return DE; }

LocalizationDocument *LocalizationDocument::GetJA() { return JA; }

LocalizationDocument *LocalizationDocument::GetKO() { return KO; }