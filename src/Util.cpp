#include "Util.hpp"

#include <utility>
#include "main.hpp"
#include "Localization.hpp"

#include "questui/shared/BeatSaberUI.hpp"
#include "Components/LocalizedText.hpp"
using namespace Diglett::Components;

Diglett::Language Diglett::getSelectedLanguage() {
    return (Language)selectedLanguage.value;
}

TMPro::TextMeshProUGUI *Diglett::CreateLocalizedText(UnityEngine::Transform *parent, std::string key, bool italic) {
    auto text = QuestUI::BeatSaberUI::CreateText(parent, "", italic);
    auto localizedText = text->get_gameObject()->AddComponent<LocalizedText *>();
    localizedText->set_key(std::move(key));
    return text;
}