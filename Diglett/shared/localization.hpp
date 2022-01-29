#pragma once

#include <string>

namespace Diglett {
    void registerLocalization(std::string csv);
    void registerLocalizationFromFile(std::string path);

    bool refreshLocalization();
}