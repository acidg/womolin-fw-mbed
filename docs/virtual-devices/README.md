# WomoLIN Virtual Devices

A virtual device (VD) in the context of the WomoLIN protocol is an endpoint of the WomoLIN network which periodically sends out its state and provides an interface to trigger commands.
Virtual devices are the interface to physical devices and take care of the protocol needed to communicate with the physical device.

The virtual device type is the type of a virtual device configured on the WomoLIN main unit and used in state broadcast messages to signal clients how to interpret the state data of a state broadcast message.

## List of Virtual Device Types

|                      Device Type | Description                                             |
| -------------------------------: | ------------------------------------------------------- |
| [`0x04`](0x04-bistable-relay.md) | Simple relay which can be SET or RESET                  |
|     [`0x05`](0x05-gas-sensor.md) | Pressure, humidity and temperature sensor (e.g. BME680) |
|  [`0x06`](0x06-planar-heater.md) | Planar/Autoterm Air 2/4D diesel heater                  |
