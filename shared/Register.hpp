#pragma once

#include "Register.hpp"
#include "LocalizationDocument.hpp"
#include "Parsing.hpp"

#include <string>

#include "beatsaber-hook/shared/rapidjson/include/rapidjson/memorystream.h"

/**
 * Used to convert assets from " laurie's fully™️-functional objcopy cmake script" to rapidjson::MemoryStreams without too much eyesore
 */
#define ASSET_TO_JSON(asset) rapidjson::MemoryStream(reinterpret_cast<char *>(asset::getData), asset::getLength())


namespace Diglett {
    class Register {

    public:
        /**
         * Register locale json files
         * @tparam L The language of the inputted file
         * @param file The input json file
         */
        template<Languages L>
        static void RegisterLocales(rapidjson::MemoryStream memoryStream) {
            LocalizationDocument ld;
            switch (L) {
                default:
                case Languages::EN:
                    ld = LocalizationDocument::GetEN();
                    break;
                case Languages::FR:
                    ld = LocalizationDocument::GetFR();
                    break;
                case Languages::ES:
                    ld = LocalizationDocument::GetES();
                    break;
                case Languages::DE:
                    ld = LocalizationDocument::GetDE();
                    break;
                case Languages::JA:
                    ld = LocalizationDocument::GetJA();
                    break;
                case Languages::KO:
                    ld = LocalizationDocument::GetKO();
                    break;
            }

            ld.AddLocalizations(Parsing::ParseJson(memoryStream));
        }
    };
}