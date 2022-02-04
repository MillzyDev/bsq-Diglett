#include "Parsing.hpp"
using namespace Diglett;

//#include "rapidxml/rapidxml.hpp"

#include "main.hpp"

#include <utility>

std::map<std::string, std::u16string> Parsing::ParseJson(const std::u16string& _json) {
    auto json = nlohmann::json::parse(_json);

    auto map = std::map<std::string, std::u16string>();

    for (const auto& el : json.items()) {
        getLogger().info(R"(Mapping: "%s": "%s")", el.key().c_str(), to_utf8((std::u16string)el.value()).c_str());
        map.insert(std::pair<std::string, std::u16string>(el.key(), el.value()));
    }

    return map;
}

/*std::map<std::string, std::u16string> Parsing::ParseXml(char16_t *xml) {
    rapidxml::xml_document<char16_t> document;
    document.parse<0>(xml);

    auto map = std::map<std::string,std::u16string>();
    auto resources = document.first_node(u"resources");

    for (rapidxml::xml_node<char16_t> *node = resources->first_node(u"string"); node; node = node->next_sibling(u"string")) {
        getLogger().info("Adding locale to map - %s: %s", to_utf8(node->first_attribute(u"name")->value()).c_str(), to_utf8(node->value()).c_str());
        map.insert(std::pair<std::string, std::u16string>(to_utf8(node->first_attribute(u"name")->value()), node->value()));
    }

    return map;
}*/

