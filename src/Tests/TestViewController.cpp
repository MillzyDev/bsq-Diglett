#include "Tests/TestViewController.hpp"

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI::BeatSaberUI;

#include "Localization.hpp"
#include "Util.hpp"

DEFINE_TYPE(Diglett::Tests, TestViewController);

void Diglett::Tests::TestViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
    auto vertical = CreateVerticalLayoutGroup(get_transform());

    auto text = CreateText(vertical->get_transform(), Diglett::Localization::get_instance()->get("Diglett:Tests:Test", Diglett::getSelectedLanguage()));
}