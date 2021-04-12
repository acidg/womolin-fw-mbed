#ifndef DEVICE_DEVICESTATEBASE_H_
#define DEVICE_DEVICESTATEBASE_H_

#include "EVirtualDeviceType.h"

namespace mainunit {
/**
 * Each virtual devices has to extend this class with all states the virtual device has to offer.
 * The resulting state object will be fetched by the framework using the serializeData
 * method and sent periodically via the state broadcast message.
 */
class DeviceStateBase {
public:
	DeviceStateBase(EVirtualDeviceType virtualDeviceType);
	virtual ~DeviceStateBase();

	/**
	 * Serializes the data of the state into the given output buffer as the state broadcast message of the virtual device.
	 * The implementation of the base class will add the virtual device type and error code.
	 * Extending classes have to first call the method of this base class and can then
	 * add remaining data to the buffer.
	 * Returns the length of the data which has been written into the buffer.
	 */
	unsigned int serializeToStateBroadcastMessage(char &outputBuffer);

	/**
	 * Deserializes and fills the state data from the given buffer.
	 * Returns the number of deserialized bytes.
	 */
	unsigned int deserializeFromStateBroadcastMessage(char &inputBuffer);
protected:
	// Error code 0 signals no error
	unsigned char errorCode = 0;
private:
	EVirtualDeviceType virtualDeviceType;
};
}

#endif /* DEVICE_DEVICESTATEBASE_H_*/
