#pragma once

#include <string>
#include <map>

typedef std::map<std::string, std::string> LocalizationMap;

namespace Diglett {
    /**
     * This acts as a container class for the XML file, it also handles parsing the text.
     */
    class LocalizationAsset {
    private:
        std::string_view text;
        LocalizationMap localizations = LocalizationMap();

        void set_text(std::string_view text);
    public:
        /**
         * @return The raw text of the XML file
         */
        [[maybe_unused]] std::string_view get_text();
        /**
         * @return The parsed localizations
         */
        const LocalizationMap &get_localizations();

        /**
         * Implicitly converts std::string_view to LocalizationAsset
         * @param str The XML text
         */
        LocalizationAsset(std::string_view str); // NOLINT
    };
}