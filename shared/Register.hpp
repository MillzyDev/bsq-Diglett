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
 * Used to convert assets from " laurie's fully™️-functional objcopy cmake script" to rapidjson::MemoryStreams without too much eyesore
 */
#define ASSET_TO_JSON(asset) rapidjson::EncodedInputStream<rapidjson::UTF16<char16_t>, rapidjson::MemoryStream>(rapidjson::MemoryStream(copyStr(asset::getData(), asset::getLength())))

//#define ASSET_TO_XML(asset) copyStr(asset::getData(), asset::getLength())

inline char16_t *copyStr(uint8_t *data, size_t length) {
    auto *str = new char16_t[length + 1];
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
        static void RegisterLocales(Logger &logger, rapidjson::EncodedInputStream<rapidjson::UTF16<char16_t>, rapidjson::MemoryStream>& memoryStream) {
            logger.info("Registering JSON locale");
            LocalizationDocument *ld = GetDocument<L>();

            ld->AddLocalizations(Parsing::ParseJson(memoryStream));
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
        static void RegisterCustomLocales(Logger &logger, const std::string& name, rapidjson::EncodedInputStream<rapidjson::UTF16<char16_t>, rapidjson::MemoryStream>& memoryStream) {
            logger.info("Registering JSON locale");
            LocalizationDocument *ld = GetCustomDocument(name);

            ld->AddLocalizations(Parsing::ParseJson(memoryStream));
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
        template<Languages L>
        static LocalizationDocument *GetDocument() {
            LocalizationDocument *ld = nullptr;
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

        static LocalizationDocument *GetCustomDocument(const std::string& name) {
            return LocalizationDocument::GetCustom(name);
        }
    };
}