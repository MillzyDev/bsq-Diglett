#pragma once

#include <map>
#include <utility>
#include <string>

#include "beatsaber-hook/shared/config/rapidjson-utils.hpp"
#include "beatsaber-hook/shared/rapidjson/include/rapidjson/encodedstream.h"
#include "beatsaber-hook/shared/rapidjson/include/rapidjson/document.h"
#include "beatsaber-hook/shared/rapidjson/include/rapidjson/encodings.h"
//#include "rapidxml/rapidxml.hpp"

#include "main.hpp"

namespace Diglett {
    class Parsing {
    public:
        static std::map<std::string, std::u16string> ParseJson(
                rapidjson::EncodedInputStream<rapidjson::UTF16<char16_t>, rapidjson::MemoryStream>& memoryStream);
        //static std::map<std::string, std::u16string> ParseXml(char16_t *xml);
    };
}