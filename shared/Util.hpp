#pragma once

#include "Language.hpp"

#if __has_include("questui/shared/BeatSaberUI.hpp")
#include "TMPro/TextMeshProUGUI.hpp"
#endif

namespace Diglett {
    Language getSelectedLanguage();

#if __has_include("questui/shared/BeatSaberUI.hpp")
    [[maybe_unused]]
    TMPro::TextMeshProUGUI *CreateLocalizedText(UnityEngine::Transform *parent, std::string key, bool italic = true);
#endif
}