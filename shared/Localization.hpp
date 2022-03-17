#pragma once

#include "LocalizationAsset.hpp"
#include "Language.hpp"

#include "beatsaber-hook/shared/utils/typedefs-string.hpp"

typedef std::map<Diglett::Language, LocalizationMap> LocalizationDocument;

namespace Diglett {
    /**
     * The main class that handles all the localization getting shenanigans
     */
    class Localization {
    private:
        static Localization *s_instance;

        LocalizationDocument document = LocalizationDocument();

        Localization();

    public:
        /**
         * This class should be treated as a Singleton otherwise shit breaks. So this exists
         * @return The used Localization * instance
         */
        static Localization *get_instance();

        /**
         * @return A map that contains all the registered localizations
         */
        LocalizationDocument &get_document();
        /**
         * Fetches a Map of key-values for localizations of a specific language
         * @param language The language to search for
         * @return The Localization document (std::map<Diglett::Language, LocalizationMap>) containing all localizations for the provided language
         */
        LocalizationMap &getLocales(Language language);
        /**
         * Gets localized text from a key and a language
         * @param key The localization key
         * @param language The language of the desired localization
         * @return A StringW instance with the localized text (USE IMMEDIATELY)
         */
        StringW get(const std::string &key, Language language);
        /**
         * Gets localized text from a key and the selected language
         * @param key The localization key
         * @return A StringW instance with the localized text (USE IMMEDIATELY)
         */
        StringW get(const std::string &key);
    };
}