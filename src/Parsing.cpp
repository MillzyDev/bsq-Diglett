#include "Parsing.hpp"
using namespace Diglett;

#include "beatsaber-hook/shared/rapidjson/include/rapidjson/document.h"
using namespace rapidjson;

#include <utility>

std::map<std::string, std::string> Parsing::ParseJson(std::string json) {
    Document document;
    document.Parse(json.c_str());

    auto map = std::map<std::string, std::string>();

    for (auto &obj : document.GetObject()) {
        map.insert(std::pair<std::string, std::string>(obj.name.GetString(), obj.value.GetString()));
    }

    return map;
}

