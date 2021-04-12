#ifndef DEVICE_IMPL_RELAY_RELAYDEVICESTATE_H_
#define DEVICE_IMPL_RELAY_RELAYDEVICESTATE_H_

#include "RelayDevice.h"

namespace mainunit {

/**
 * Possible switch statuses of a relay device.
 */
enum ERelayDeviceSwitchStatus : unsigned char {
	RESET = 0, SET = 1
};

/**
 * Device state for relay devices.
 */
class RelayDeviceState: DeviceStateBase {
public:
	RelayDeviceState() :
			DeviceStateBase(RELAY) {
	}
	virtual ~RelayDeviceState();
	ERelayDeviceSwitchStatus switchStatus = RESET;
};
}
/* namespace mainunit */

#endif /* DEVICE_IMPL_RELAY_RELAYDEVICESTATE_H_ */
