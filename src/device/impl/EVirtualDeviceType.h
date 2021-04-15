#ifndef DEVICE_EVIRTUALDEVICETYPE_H_
#define DEVICE_EVIRTUALDEVICETYPE_H_

/**
 * Mapping of virtual device types to an unique id.
 */
enum EVirtualDeviceType {
	RELAY = 0x04, // External/Bistable relay connected to the MAX4896 ICs on the main unit
	BME680 = 0x05, // BME680
	PLANAR = 0x06, // Autoterm/Planar diesel heater
	TRUMA_COMBI_E = 0x07 // Truma Heater
};

#endif /* DEVICE_EVIRTUALDEVICETYPE_H_ */
