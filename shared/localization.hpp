#pragma once

#include <string>

namespace DiGlott {
    void registerLocalization(std::string csv);
    void registerLocalizationFromFile(std::string path);

    bool refreshLocalization();
}