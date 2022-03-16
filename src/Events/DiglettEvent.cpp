#include "Events/DiglettEvent.hpp"

void Diglett::Events::DiglettEvent::Invoke() {
    for (auto func : delegates) {
        func->Invoke();
    }
}

void Diglett::Events::DiglettEvent::AddListener(Diglett::Events::DiglettDelegate *delegate) {
    delegates.push_back(delegate);
}

void Diglett::Events::DiglettEvent::RemoveListener(Diglett::Events::DiglettDelegate *delegate) {
    std::remove(delegates.begin(), delegates.end(), delegate); // NOLINT
}
