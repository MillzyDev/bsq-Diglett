#include "Events/DiglettDelegate.hpp"

#include <vector>

typedef std::vector<Diglett::Events::DiglettDelegate *> DelegateList;

namespace Diglett::Events {
    struct DiglettEvent {
    private:
        DelegateList delegates = DelegateList();

    public:
        void Invoke();
        void AddListener(DiglettDelegate *delegate);
        void RemoveListener(DiglettDelegate *delegate);
    };
}