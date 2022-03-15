#include "Tests/TestViewController.hpp"

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI::BeatSaberUI;

#include "Localization.hpp"
#include "Util.hpp"
#include "main.hpp"

DEFINE_TYPE(Diglett::Tests, TestViewController);

void Diglett::Tests::TestViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
    getLogger().info("Localized text is: %s", static_cast<std::string>(Diglett::Localization::get_instance()->get("Diglett:Tests:Test", Diglett::getSelectedLanguage())).c_str());
    if (firstActivation) {
        auto vertical = CreateVerticalLayoutGroup(get_transform());

        CreateText(vertical->get_transform(), Diglett::Localization::get_instance()->get("Diglett:Tests:Test", Diglett::getSelectedLanguage()));
    }
}