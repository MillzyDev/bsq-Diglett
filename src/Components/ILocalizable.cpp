#include "Components/ILocalizable.hpp"
using namespace Diglett::Components;

DEFINE_TYPE(Diglett::Components, ILocalizable)

void ILocalizable::Awake() {
    OnLocalize();
}

void ILocalizable::OnLocalize() {
    onLocalizeEvent.Invoke();
}