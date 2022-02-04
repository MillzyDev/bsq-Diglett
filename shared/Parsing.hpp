#pragma once

#include <map>
#include <utility>
#include <string>

#include "nlohmann/json.hpp"
//#include "rapidxml/rapidxml.hpp"

namespace Diglett {
    class Parsing {
    public:
        static std::map<std::string, std::u16string> ParseJson(const std::u16string& json);
        //static std::map<std::string, std::u16string> ParseXml(char16_t *xml);
    };
}