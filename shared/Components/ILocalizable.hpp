#include "custom-types/shared/macros.hpp"

#include "UnityEngine/MonoBehaviour.hpp"
#include "TMPro/TMP_Text.hpp"

#include "Events/DiglettEvent.hpp"

DECLARE_CLASS_CODEGEN(Diglett::Components, ILocalizable, UnityEngine::MonoBehaviour,
    DECLARE_INSTANCE_METHOD(void, Awake);
    DECLARE_INSTANCE_METHOD(void, OnLocalize);

public:
    Diglett::Events::DiglettEvent onLocalizeEvent;
)