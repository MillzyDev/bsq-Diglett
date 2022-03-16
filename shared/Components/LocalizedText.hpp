#include "custom-types/shared/macros.hpp"

#include "Components/ILocalizable.hpp"
#include "Localization.hpp"

#define DECLARE_PROPERTY(retval, name)  \
private: retval _##name;                \
public:                                 \
void set_##name(retval value);          \
retval get_##name();


DECLARE_CLASS_CODEGEN(Diglett::Components, LocalizedText, ILocalizable,
    DECLARE_INSTANCE_METHOD(void, Start);
    DECLARE_INSTANCE_METHOD(void, OnDestroy);

    DECLARE_INSTANCE_FIELD(TMPro::TMP_Text *, text);

    DECLARE_PROPERTY(std::string, key)
    DECLARE_PROPERTY(Diglett::Localization *, localization)

public:
    static Diglett::Events::DiglettDelegate *localize;
)