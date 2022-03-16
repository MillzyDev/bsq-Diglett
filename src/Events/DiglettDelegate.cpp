#include "Events/DiglettDelegate.hpp"

void Diglett::Events::DiglettDelegate::Invoke() {
    delegate();
}

Diglett::Events::DiglettDelegate::DiglettDelegate(std::function<void()> callback) {
    delegate = std::move(callback);
}
