#pragma once

#include <map>
#include <string>

namespace Diglett {
    class Parsing {
    public:
        static std::map<std::string, std::string> ParseJson(std::string json);
        //std::map<std::string, std::string> ParseXml(std::string xml);
    };
}