#pragma once

#include "Languages.hpp"
#include "Format.hpp"

#include <string>
#include <vector>
#include <map>
#include <utility>

namespace Diglett {
    class LocalizationDocument {

    private:
        static LocalizationDocument *EN;
        static LocalizationDocument *FR;
        static LocalizationDocument *ES;
        static LocalizationDocument *DE;
        static LocalizationDocument *JA;
        static LocalizationDocument *KO;
        static std::map<std::string, LocalizationDocument *> customLocalizationDocuments;

        std::vector<std::pair<std::string, std::string>> translations;

    public:
        LocalizationDocument();

        /**
         *
         * @param key The key of the desired localization
         * @return  The localized string for the document language
         */
        std::string Get(const std::string& key);

        /**
         *
         * @return The current set of English locales
         */
        static LocalizationDocument *GetEN();

        /**
         *
         * @return The current set of French locales
         */
        static LocalizationDocument *GetFR();

        /**
         *
         * @return The current set of Spanish locales
         */
        static LocalizationDocument *GetES();

        /**
         *
         * @return The current set of German locales
         */
        static LocalizationDocument *GetDE();

        /**
         *
         * @return The current set of Japanese locales
         */
        static LocalizationDocument *GetJA();

        /**
         *
         * @return The current set of Korean locales
         */
        static LocalizationDocument *GetKO();

        /**
         * Gets a LocalizationDocument for a custom language
         * @param name The name/id of the language to get
         * @return A LocalizationDocument of the custom language
         */
        static LocalizationDocument *GetCustom(std::string name);

        /**
         * Gets the LocalizationDocument of that language the is currently selected by Polyglot
         * @return A LocalizationDocument of the currently selected language
         */
        static LocalizationDocument *GetSelected();

        /**
         * Adds new localisations to the document from the contents of a file
         * @param map The map of all the new key-value entries
         */
        void AddLocalizations(std::vector<std::pair<std::string, std::string>> map);
    };
}