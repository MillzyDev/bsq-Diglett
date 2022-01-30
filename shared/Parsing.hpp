#pragma once

#include <map>
#include <utility>
#include <string>

#include "beatsaber-hook/shared/rapidjson/include/rapidjson/memorystream.h"

namespace Diglett {
    class Parsing {
    public:
        static std::map<std::string, std::string> ParseJson(rapidjson::MemoryStream memoryStream);
        static std::map<std::string, std::string> ParseXml(char *xml);
    };
}