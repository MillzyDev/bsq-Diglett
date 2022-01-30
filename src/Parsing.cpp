#include "Parsing.hpp"
using namespace Diglett;

#include "beatsaber-hook/shared/rapidjson/include/rapidjson/document.h"
using namespace rapidjson;

#include "main.hpp"

#include <utility>

std::vector<std::pair<std::string, std::string>> Parsing::ParseJson(rapidjson::MemoryStream memoryStream) {
    Document document;
    document.ParseStream(memoryStream);

    auto map = std::vector<std::pair<std::string, std::string>>();

    for (auto &obj : document.GetObject()) {
        getLogger().info("Adding locale to map - %s: %s", obj.name.GetString(), obj.value.GetString());
        map.emplace_back(obj.name.GetString(), obj.value.GetString());
    }

    return map;
}

