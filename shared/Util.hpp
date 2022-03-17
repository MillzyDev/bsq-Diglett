#pragma once

#include "Language.hpp"

#if __has_include("questui/shared/BeatSaberUI.hpp")
#include "TMPro/TextMeshProUGUI.hpp"
#endif

namespace Diglett {
    /** @file Util.hpp
     * Gets the current language Polyglot has marked as selected
     * @return The Polyglot::Language converted to Diglett::Language
     */
    Language getSelectedLanguage();

#if __has_include("questui/shared/BeatSaberUI.hpp")
    /** @file Util.hpp
     * Creates a new TMP_Text object with QuestUI, adds the LocalizationText and sets the key for you!
     * @param parent The Text's parent transform, e.g a layout group
     * @param key the localization key to use initially, this can be changed
     * @param italic Whether the text should be italic
     * @return The created TextMeshProUGUI *
     * @example @code CreateLocalizedText(layout->get_transform(), "Diglett:Tests:Test"); @endcode
     */
    [[maybe_unused]]
    TMPro::TextMeshProUGUI *CreateLocalizedText(UnityEngine::Transform *parent, std::string key, bool italic = true);
#endif
}