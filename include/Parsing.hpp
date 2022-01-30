#pragma once

#include <vector>
#include <utility>
#include <string>

#include "beatsaber-hook/shared/rapidjson/include/rapidjson/memorystream.h"

namespace Diglett {
    class Parsing {
    public:
        static std::vector<std::pair<std::string, std::string>> ParseJson(rapidjson::MemoryStream memoryStream);
        //std::map<std::string, std::string> ParseXml(std::string xml);
    };
}