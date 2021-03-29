#include <map>

namespace mainunit
{
    template <typename T>
    /**
     * Wrapper for states. A state is the value of a specific property a device can offer, such as temperature, voltage level, ...
     */
    class DeviceState
    {
    private:
        T* value;
        std::string name;

    public:
        /** Returns the value of the state. */
        T* getValue();

        /** Name of the state. */
        std::string getName();
    };
}