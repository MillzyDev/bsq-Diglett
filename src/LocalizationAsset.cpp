#include "LocalizationAsset.hpp"

#include "tinyxml2/shared/tinyxml2.h"

#define RESOURCES_NODE "resources"
#define STRING_NODE "string"

void Diglett::LocalizationAsset::set_text(std::string_view text) {
    this->text = text;
}

std::string_view Diglett::LocalizationAsset::get_text() {
    return text;
}

const LocalizationMap &Diglett::LocalizationAsset::get_localizations() {
    return localizations;
}

Diglett::LocalizationAsset::LocalizationAsset(std::string_view str) {
    set_text(str);

    tinyxml2::XMLDocument doc;
    doc.Parse(str.data());

    auto resources = doc.FirstChildElement(RESOURCES_NODE);

    for (auto string = resources->FirstChildElement(STRING_NODE); string; string = string->NextSiblingElement(STRING_NODE)) {
        localizations.insert(
                std::string_view(string->FindAttribute("name")->Value()),
                std::string_view(string->Value())
                );
    }
}