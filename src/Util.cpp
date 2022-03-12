#include "Util.hpp"

#include "Polyglot/Localization.hpp"

Diglett::Language Diglett::getSelectedLanguage() {
    return (Diglett::Language) Polyglot::Localization::get_Instance()->get_SelectedLanguage().value;
}