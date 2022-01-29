#pragma once

#include "Format.hpp"
#include "Languages.hpp"

#include <string>

/**
 * Used to convert assets from " laurie's fully™️-functional objcopy cmake script" to strings without too much eyesore
 */
#define ASSET_TO_STRING(asset)                                  \
    char *asset##_str = new char[asset::getLength() + 1];       \
    memcpy(asset##_str, asset::getData, asset::getLength());    \
    asset##_str[asset::getLength()] = '\0'                      \

namespace Diglett {
    class Register {

    public:
        /**
         * Register locale files
         * @tparam F The file format of the inputted file
         * @tparam L The language of the inputted file
         * @param file The contents of the file
         */
        template<Format F, Languages L>
        static void RegisterLocales(std::string file);
    };
}