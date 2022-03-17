#include "Components/LocalizedText.hpp"
#include "main.hpp"
using namespace Diglett::Components;
using namespace TMPro;

#include <utility>

DEFINE_TYPE(Diglett::Components, LocalizedText)

void LocalizedText::Awake() {
    text = GetComponent<TMP_Text *>();
    text == nullptr ? getLogger().info("Text is NULLPTR!") : getLogger().info("Text is fine!");
}

void LocalizedText::set_key(std::string value) {
    _key = std::move(value);
    text->set_text(
            {get_localization()->get(_key)}
            );
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