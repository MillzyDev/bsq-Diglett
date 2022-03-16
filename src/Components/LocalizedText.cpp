#include "Components/LocalizedText.hpp"

#include <utility>
using namespace Diglett::Components;
using namespace Diglett::Events;
using namespace TMPro;

DEFINE_TYPE(Diglett::Components, LocalizedText)

DiglettDelegate *LocalizedText::localize = nullptr;

void LocalizedText::Start() {
    text = GetComponent<TMP_Text *>();

    if (localize == nullptr) {
        new DiglettDelegate([this]() {
            text->set_text(get_localization()->get(get_key()));
        });
    }

    onLocalizeEvent.AddListener(localize);
}

void LocalizedText::OnDestroy() {
    onLocalizeEvent.RemoveListener(localize);
}

void LocalizedText::set_key(std::string value) {
    _key = std::move(value);
    onLocalizeEvent.Invoke();
}

std::string LocalizedText::get_key() {
    return _key;
}

Diglett::Localization *LocalizedText::get_localization() {
    if (_localization == nullptr) {
        _localization = Localization::get_instance();
    }
    return _localization;
}

void LocalizedText::set_localization([[maybe_unused]] Diglett::Localization *value) {}