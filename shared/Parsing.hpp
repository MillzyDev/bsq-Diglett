#pragma once

#include <vector>
#include <utility>
#include <string>

#include "beatsaber-hook/shared/rapidjson/include/rapidjson/memorystream.h"

namespace Diglett {
    class Parsing {
    public:
        static std::vector<std::pair<std::string, std::string>> ParseJson(rapidjson::MemoryStream memoryStream);
        static std::vector<std::pair<std::string, std::string>> ParseXml(char *xml);
    };
}