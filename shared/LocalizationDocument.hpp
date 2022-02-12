#pragma once

#include "Languages.hpp"

#include <string>
#include <map>
#include <utility>

#if defined(HAS_CODEGEN) || __has_include("Polyglot/Localization.hpp")
#include "Polyglot/Localization.hpp"
#elif

#endif

#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"
#include "beatsaber-hook/shared/utils/utils.h"

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

        std::map<std::string, std::u16string> translations;

    public:
        LocalizationDocument();

        /**
         *
         * @param key The key of the desired localization
         * @return  The localized string for the document language
         */
        std::u16string Get(const std::string& key);

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
         * Gets a LocalizationDocument for a custom language WARNING: WILL CAUSE NULLPTR DEREF
         * @param name The name/id of the language to get
         * @return A LocalizationDocument of the custom language
         */
        static LocalizationDocument *GetCustom(const std::string& name);

        /**
         * Gets the LocalizationDocument of that language the is currently selected by Polyglot
         * @return A LocalizationDocument of the currently selected language
         */
        inline static LocalizationDocument *GetSelected() {
#if defined(HAS_CODEGEN) || __has_include("Polyglot/Localization.hpp")
            Polyglot::Language selectedLanguage = Polyglot::Localization::get_Instance()->get_SelectedLanguage();
            auto selected = (Diglett::Language) selectedLanguage.value;
#elif
            static auto getInstanceMethodInfo = CRASH_UNLESS((il2cpp_utils::FindMethodUnsafe("Polyglot", "Localization", "get_Instance", 0)));
            auto instance = il2cpp_utils::RunMethod(nullptr, getInstanceMethodInfo);

            static auto getSelectedLanguageMethodInfo = CRASH_UNLESS(il2cpp_utils::FindMethodUnsafe(instance.value(), "get_SelectedLanguage", 0));
            auto selectedLanguage = il2cpp_utils::RunMethod<int>(instance, getSelectedLanguageMethodInfo);

            auto selected = (Diglett::Language) selectedLanguage;
#endif

            switch (selected) {
                case Diglett::Language::French:
                    return GetFR();
                case Diglett::Language::Spanish:
                    return GetES();
                case Diglett::Language::German:
                    return GetDE();
                case Diglett::Language::Japanese:
                    return GetJA();
                case Diglett::Language::Korean:
                    return GetKO();
                case Diglett::Language::English:
                default:
                    return GetEN();
            }
        }

        /**
         * Adds new localisations to the document from the contents of a file
         * @param map The map of all the new key-value entries
         */
        void AddLocalizations(std::map<std::string, std::u16string> map);
    };
}