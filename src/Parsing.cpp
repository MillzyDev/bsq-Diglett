#include "Parsing.hpp"
using namespace Diglett;

#include "beatsaber-hook/shared/rapidjson/include/rapidjson/document.h"
using namespace rapidjson;

#include "main.hpp"

#include <utility>

std::map<std::string, std::string> Parsing::ParseJson(rapidjson::MemoryStream memoryStream) {
    Document document;
    document.ParseStream(memoryStream);

    auto map = std::map<std::string, std::string>();

    for (auto &obj : document.GetObject()) {
        getLogger().info("Adding locale to map - %s: %s", obj.name.GetString(), obj.value.GetString());
        map.insert(std::pair<std::string, std::string>(obj.name.GetString(), obj.value.GetString()));
    }

    return map;
}

