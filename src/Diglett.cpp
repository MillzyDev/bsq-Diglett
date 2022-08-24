#include "Diglett.hpp"
#include "main.hpp"

#include "beatsaber-hook/shared/utils/hooking.hpp"

#include "Polyglot/Localization.hpp"

Polyglot::Language selectedLanguage;

MAKE_HOOK_MATCH(Localization_set_SelectedLanguage, &Polyglot::Localization::set_SelectedLanguage,
    void, Polyglot::Localization *self, Polyglot::Language value
) {
    selectedLanguage = value;
    getLogger().info("Selected language is NO %i", value.value);

    Localization_set_SelectedLanguage(self, value);
}

void Diglett::Init() {
    INSTALL_HOOK(getLogger(), Localization_set_SelectedLanguage)
}