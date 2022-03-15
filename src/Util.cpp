#include "Util.hpp"
#include "main.hpp"
#include "Localization.hpp"

#include "Polyglot/Localization.hpp"

Diglett::Language Diglett::getSelectedLanguage() {
    getLogger().info("Selected language is NO %i", Polyglot::Localization::get_Instance()->get_SelectedLanguage().value);
    return (Diglett::Language) Polyglot::Localization::get_Instance()->get_SelectedLanguage().value;
}
