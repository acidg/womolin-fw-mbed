#ifndef DEVICE_VIRTUALDEVICEBASE_H_
#define DEVICE_VIRTUALDEVICEBASE_H_

#include <type_traits>

#include "DeviceStateBase.h"
#include "ICommand.h"

namespace mainunit {

template<typename T> // TODO: Make sure T extends DeviceStateBase

/**
 * Devices are single external peripherals connected to the WomoLIN board.
 * This interface offers a generic way to get the current state of the device and available commands which can be sent to the device.
 * A specific device type can be registered multiple times in the WomoLIN registry (e.g. two separate temperature sensors)
 */
class VirtualDeviceBase {
public:
	virtual ~VirtualDeviceBase();
	/**
	 * Called, when the device should update its state.
	 * If errors occurred during updates, the error code in the state object should be used for signaling.
	 */
	virtual void updateState(T *state);

	/**
	 * Executes the command with the given parameters. If no command with
	 * the given command type is known to the virtual device, nothing will happen.
	 */
	void executeCommand(unsigned char commandType, ICommandParameter parameters);

protected:
	/**
	 * Base constructor for virtual devices. The state object and commands should already be allocated.
	 */
	VirtualDeviceBase(T *state, ICommand *commands);

private:
	/**
	 * The internal state object of the device, which will be sent to clients.
	 * Set via constructor. The idea here is to reserve all memory needed for the states on instantiation of the class.
	 */
	T *state;

	/**
	 * Commands available for the device.
	 */
	ICommand *commands;
};
}

#endif /* DEVICE_VIRTUALDEVICEBASE_H_ */
