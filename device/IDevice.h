#include "DeviceState.h"
#include "ICommand.h"

namespace mainunit
{
    template <typename T>
    /**
     * Devices are single external peripherals connected to the WomoLIN board.
     * This interface offers a generic way to get the current state of the device and available commands which can be sent to the device.
     * A specific device type can be registered multiple times in the WomoLIN registry (e.g. two separate temperature sensors)
     */
    class IDevice
    {
    public:
        /**
         * Communicates with the peripheral devices and retrieves all its current states.
         * Implementors should pull all available states from the hardware and return it as a 
         */
        virtual DeviceState<T>[] get_current_states();

        /**
         * Returns all available commands for this device.
         */
        virtual ICommand<T>[] get_available_commands();
    };
}