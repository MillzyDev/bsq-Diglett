#include "custom-types/shared/macros.hpp"

#include "UnityEngine/MonoBehaviour.hpp"
#include "TMPro/TMP_Text.hpp"
#include "Localization.hpp"

#define DECLARE_PROPERTY(retval, name)  \
private: retval _##name;                \
public:                                 \
void set_##name(retval value);          \
retval get_##name();


DECLARE_CLASS_CODEGEN(Diglett::Components, LocalizedText, UnityEngine::MonoBehaviour,
    DECLARE_INSTANCE_METHOD(void, Awake);

    DECLARE_INSTANCE_FIELD(TMPro::TMP_Text *, text);

private:
    std::string _key;
    Diglett::Localization *_localization;
public:
    void set_key(std::string value);
    std::string get_key();

    Diglett::Localization *get_localization();
)