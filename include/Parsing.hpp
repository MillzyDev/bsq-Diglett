#pragma once

#include <map>
#include <string>

#include "beatsaber-hook/shared/rapidjson/include/rapidjson/memorystream.h"

namespace Diglett {
    class Parsing {
    public:
        static std::map<std::string, std::string> ParseJson(rapidjson::MemoryStream memoryStream);
        //std::map<std::string, std::string> ParseXml(std::string xml);
    };
}