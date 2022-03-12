#include "LocalizationAsset.hpp"

#include "rapidxml/rapidxml.hpp"

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

    rapidxml::xml_document<> doc;
    doc.parse<0>(const_cast<char *>(str.data()));
    auto resources = doc.first_node(RESOURCES_NODE);

    for (auto node = resources->first_node(STRING_NODE); node; node = node->next_sibling(STRING_NODE)) {
        localizations.emplace(std::pair<std::string_view, std::string_view>(
                std::string_view(node->first_attribute("name")->value()),
                std::string_view(node->value()))
                );
    }
}