#pragma once

#include "Format.hpp"
#include "Languages.hpp"

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
        static void RegisterLocales(rapidjson::MemoryStream file);
    };
}