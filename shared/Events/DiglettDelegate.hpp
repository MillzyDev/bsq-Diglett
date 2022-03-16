#include <functional>
#include <utility>

namespace Diglett::Events {
    class DiglettDelegate {
    private:
        std::function<void()> delegate;
    public:
        DiglettDelegate(std::function<void()> callback); // NOLINT

        void Invoke();
    };
}