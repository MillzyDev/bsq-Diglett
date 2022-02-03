#include "Parsing.hpp"
using namespace Diglett;

#include "beatsaber-hook/shared/rapidjson/include/rapidjson/document.h"
#include "beatsaber-hook/shared/rapidjson/include/rapidjson/encodings.h"
#include "rapidxml/rapidxml.hpp"

#include "main.hpp"

#include <utility>

std::map<std::string, std::u16string> Parsing::ParseJson(
        rapidjson::EncodedInputStream<rapidjson::UTF16<char16_t>, rapidjson::MemoryStream>& memoryStream) {

    rapidjson::GenericDocument<rapidjson::UTF16<char16_t>> document;
    document.ParseStream(memoryStream);

    auto map = std::map<std::string, std::u16string>();

    for (auto &obj : document.GetObject()) {
        getLogger().info("Adding locale to map - %s: %s", to_utf8(obj.name.GetString()).c_str(), to_utf8(obj.value.GetString()).c_str());
        map.insert(std::pair<std::string, std::u16string>(to_utf8(obj.name.GetString()), obj.value.GetString()));
    }

    return map;
}
static std::map<std::string, std::u16string> ParseXml(char16_t *xml);
}

std::map<std::string, std::u16string> Parsing::ParseXml(char16_t *xml) {
    rapidxml::xml_document<char16_t> document;
    document.parse<0>(xml);

    auto map = std::map<std::string,std::u16string>();
    auto resources = document.first_node(u"resources");

    for (rapidxml::xml_node<char16_t> *node = resources->first_node(u"string"); node; node = node->next_sibling(u"string")) {
        getLogger().info("Adding locale to map - %s: %s", to_utf8(node->first_attribute(u"name")->value()).c_str(), to_utf8(node->value()).c_str());
        map.insert(std::pair<std::string, std::u16string>(to_utf8(node->first_attribute(u"name")->value()), node->value()));
    }

    return map;
}

