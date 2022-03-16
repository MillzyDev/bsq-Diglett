#pragma once

#include <string>
#include <map>

typedef std::map<std::string, std::string> LocalizationMap;

namespace Diglett {
    class LocalizationAsset {
    private:
        std::string_view text;
        LocalizationMap localizations = LocalizationMap();

        void set_text(std::string_view text);
    public:
        [[maybe_unused]] std::string_view get_text();
        const LocalizationMap &get_localizations();

        LocalizationAsset(std::string_view str); // NOLINT
    };
}