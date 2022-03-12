#pragma once

#include <string>
#include <unordered_map>

typedef std::unordered_map<std::string_view, std::string_view> LocalizationMap;

namespace Diglett {
    class LocalizationAsset {
    private:
        std::string_view text;
        LocalizationMap localizations = LocalizationMap();

        void set_text(std::string_view text);
    public:
        std::string_view get_text();
        const LocalizationMap &get_localizations();

        LocalizationAsset(std::string_view str); // NOLINT
    };
}