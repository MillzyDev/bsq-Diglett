#pragma once

#include "Register.hpp"
#include "LocalizationDocument.hpp"
#include "Parsing.hpp"

#include <string>

#include "beatsaber-hook/shared/rapidjson/include/rapidjson/memorystream.h"

#include "rapidxml/rapidxml.hpp"

/**
 * Used to convert assets from " laurie's fully™️-functional objcopy cmake script" to rapidjson::MemoryStreams without too much eyesore
 */
#define ASSET_TO_JSON(asset) rapidjson::MemoryStream(copyStr(asset::getData(), asset::getLength()), asset::getLength())

#define ASSET_TO_XML(asset) copyStr(asset::getData(), asset::getLength())

inline char *copyStr(uint8_t *data, size_t length) {
    char* str = new char[length + 1];
    memcpy(str, data, length);
    str[length] = '\0';
    return str;
}

namespace Diglett {
    class Register {

    public:


        /**
         * Register json locale files
         * @tparam L The language of the inputted file
         * @param file The input json file
         */
        template<Languages L>
        static void RegisterLocales(rapidjson::MemoryStream memoryStream) {
            getLogger().info("Registering JSON locale");
            LocalizationDocument *ld = GetDocument<L>();

            ld->AddLocalizations(Parsing::ParseJson(memoryStream));
        }

        /**
         * Register xml locale files
         * @tparam L  The language of the inputted file
         * @param xml  The input xml file
         */
        template<Languages L>
        static void RegisterLocales(char *xml) {
            getLogger().info("Registering XML locale");
            LocalizationDocument *ld = GetDocument<L>();

            ld->AddLocalizations(Parsing::ParseXml(xml));
        }

    private:
        template<Languages L>
        static LocalizationDocument *GetDocument() {
            LocalizationDocument *ld =  nullptr;
            switch (L) {
                case Languages::English:
                    ld = LocalizationDocument::GetEN();
                    break;
                case Languages::French:
                    ld = LocalizationDocument::GetFR();
                    break;
                case Languages::Spanish:
                    ld = LocalizationDocument::GetES();
                    break;
                case Languages::German:
                    ld = LocalizationDocument::GetDE();
                    break;
                case Languages::Japanese:
                    ld = LocalizationDocument::GetJA();
                    break;
                case Languages::Korean:
                    ld = LocalizationDocument::GetKO();
                    break;
            }
            return ld;
        }
    };
}