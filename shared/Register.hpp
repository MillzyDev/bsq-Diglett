#pragma once

#include "Register.hpp"
#include "LocalizationDocument.hpp"
#include "Parsing.hpp"

#include <string>
#include <utility>

#include "beatsaber-hook/shared/rapidjson/include/rapidjson/memorystream.h"
#include "beatsaber-hook/shared/rapidjson/include/rapidjson/encodedstream.h"
#include "beatsaber-hook/shared/rapidjson/include/rapidjson/encodings.h"
#include "beatsaber-hook/shared/utils/logging.hpp"

//#include "rapidxml/rapidxml.hpp"

/**
 * Used to convert assets from " laurie's fully™️-functional objcopy cmake script" to std::u16strings without too much eyesore
 */


#define ASSET_TO_STR(asset) copyStr(asset::getData(), asset::getLength())

inline std::u16string copyStr(uint8_t *data, size_t length) {
    auto *str = new char16_t[length + 1];
    memcpy(str, data, length);
    str[length] = '\0';
    return {str};
}

namespace Diglett {
    class Register {

    public:
        /**
         * Register json locale files
         * @tparam L The language of the inputted file
         * @param file The input json file
         */
        template<Language L>
        static void RegisterLocales(Logger &logger, const std::u16string& json) {
            logger.info("Registering JSON locale");
            LocalizationDocument *ld = GetDocument<L>();

            ld->AddLocalizations(Parsing::ParseJson(json));
        }

        ///**
        // * Register xml locale files
        // * @tparam L  The language of the inputted file
        // * @param xml  The input xml file
        // */
        //template<Languages L>
        //static void RegisterLocales(Logger &logger, char16_t *xml) {
        //    logger.info("Registering XML locale");
        //    LocalizationDocument *ld = GetDocument<L>();
        //
        //    ld->AddLocalizations(Parsing::ParseXml(xml));
        //}

        /**
         * Register json custom locale files WARNING: WILL CAUSE NULLPTR DEREF
         * @param file The input json file
         */
        static void RegisterCustomLocales(Logger &logger, const std::string& name, const std::u16string& json) {
            logger.info("Registering JSON locale");
            LocalizationDocument *ld = GetCustomDocument(name);

            ld->AddLocalizations(Parsing::ParseJson(json));
        }

        ///**
        // * Register xml custom locale files WARNING: WILL CAUSE NULLPTR DEREF
        // * @param xml  The input xml file
        // */
        //static void RegisterCustomLocales(Logger &logger, const std::string& name, char16_t *xml) {
        //    logger.info("Registering XML locale");
        //    LocalizationDocument *ld = GetCustomDocument(name);
        //
        //    ld->AddLocalizations(Parsing::ParseXml(xml));
        //}

    private:
        template<Language L>
        static LocalizationDocument *GetDocument() {
            LocalizationDocument *ld = nullptr;
            switch (L) {
                case Language::English:
                    ld = LocalizationDocument::GetEN();
                    break;
                case Language::French:
                    ld = LocalizationDocument::GetFR();
                    break;
                case Language::Spanish:
                    ld = LocalizationDocument::GetES();
                    break;
                case Language::German:
                    ld = LocalizationDocument::GetDE();
                    break;
                case Language::Japanese:
                    ld = LocalizationDocument::GetJA();
                    break;
                case Language::Korean:
                    ld = LocalizationDocument::GetKO();
                    break;
            }
            return ld;
        }

        static LocalizationDocument *GetCustomDocument(const std::string& name) {
            return LocalizationDocument::GetCustom(name);
        }
    };
}