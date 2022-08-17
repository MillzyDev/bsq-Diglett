#include "LocalizationAsset.hpp"
#include "main.hpp"

#include <string>

#include "tinyxml2/shared/tinyxml2.h"

#define RESOURCES_NODE "resources"
#define STRING_NODE "string"
#define NEW_LINE "\\n"

void Diglett::LocalizationAsset::set_text(std::string_view text) {
    this->text = text;
}

[[maybe_unused]] std::string_view Diglett::LocalizationAsset::get_text() {
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

    std::string newLine = NEW_LINE;

    for (auto string = resources->FirstChildElement(STRING_NODE); string != nullptr; string = string->NextSiblingElement(STRING_NODE)) {
        std::string content = string->GetText();

        size_t pos = content.find(newLine);
        while (pos != std::string::npos) {
            content.replace(pos, newLine.size(), "\n");
            pos = content.find(newLine, pos + std::string("\n").size());
        }

        localizations.emplace(
                std::string(string->FindAttribute("name")->Value()),
                std::string_view(string->GetText())
                );
        getLogger().info("Registering key: %s", string->FindAttribute("name")->Value());
    }

}