#ifndef DEVICE_IMPL_RELAYDEVICE_H_
#define DEVICE_IMPL_RELAYDEVICE_H_

#include "VirtualDeviceBase.h"
#include "RelayDeviceState.h"

namespace mainunit {

/**
 * Virtual device for Relays and switches connected to the MAX4896 SPI drivers
 */
class RelayDevice: public VirtualDeviceBase<RelayDeviceState> {
public:
	RelayDevice(int output) :
			VirtualDeviceBase<RelayDeviceState>(new RelayDeviceState { }, {/* TODO */}), output(output) {
	}
	virtual ~RelayDevice();
private:
	int output;
};

} /* namespace mainunit */

#endif /* DEVICE_IMPL_RELAYDEVICE_H_ */
