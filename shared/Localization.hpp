#pragma once

#include "LocalizationAsset.hpp"
#include "Language.hpp"

#include "beatsaber-hook/shared/utils/typedefs-string.hpp"

typedef std::unordered_map<Diglett::Language, LocalizationMap> LocalizationDocument;

namespace Diglett {
    class Localization {
    private:
        static Localization *s_instance;

        LocalizationDocument document = LocalizationDocument();

        Localization();

    public:
        static Localization *get_instance();

        LocalizationDocument get_document();
        LocalizationMap getLocales(Language language);
        StringW get(std::string_view key, Language language);
    };
}