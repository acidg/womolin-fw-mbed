# WomoLIN Protocol

This document describes the protocol used for exchange of data between client devices and the WomoLIN main unit(s).

## History

| Version | Changes                     |
| ------- | --------------------------- |
| v1.0    | First draft of the protocol |

## Physical Layer

The WomoLIN protocol is based on CANBus with 11-bit identifiers (CAN 2.0A).

## Software Layer

There are two kind of messages on the bus:

* state broadcasts
* commands

A virtual device in the context of the WomoLIN protocol is an endpoint of the WomoLIN network which periodically sends out its state and provides an interface to trigger commands.
Virtual devices are the interface to physical devices and take care of the protocol needed to communicate with the physical device.
Each virtual device or endpoint uses a unique 11-bit identifier (id).

This id is used by the main unit to broadcast the virtual device's state and by the clients to trigger commands.
The CAN bus protocol prioritizes messages with higher id.
In order to be prioritize commands on the bus, the id for command messages should be higher than for state broadcasts.

Therefore, commands have the MSB of the id set to 1, whereas state broadcast must have the MSB set to 0.
This ensures that commands are always prioritized on the bus and makes it easier for the main unit to identify commands.

The other 10 bits of the id are unique for each virtual device configured on the WomoLIN board.
```
                      CAN Bus
                        H L
                        │ │     ┌───────────────────┐
                        │ │     │ WomoLIN Main Unit │
┌───────────────┐       │ │     │                   │
│ Client        ├───────┼─┤     │ ┌───────────────┐ │  ┌──────────────────┐
| Display Unit 1|       | ├─────┼─┤ Virtual Device| |  | Physical Device  |
│               │───────┤ |     | | Heater        ├─┼──┤                  │
└───────────────┘       ├─┼─────┼─┤ ID: 0x0F1     │ │  │ Planar 2D        │
                        │ │     │ └───────────────┘ │  └──────────────────┘
┌───────────────┐       │ │     │                   │
│ Client        ├───────┼─┤     │ ┌───────────────┐ │  ┌──────────────────┐
│ Display Unit 2│       │ ├─────┼─┤ Virtual Device│ │  │ Physical Device  │
│               ├───────┤ │     │ │ Water Tank    ├─┼──┤                  │
└───────────────┘       ├─┼─────┼─┤ ID: 0x004     │ │  │ Tank Sensor      │
                        │ │     │ └───────────────┘ │  └──────────────────┘
┌───────────────┐       │ │     │         .         │
│ Client        ├───────┼─┤     │         .         │
│ Tank Monitor  │       │ │     │         .         │
│               ├───────┤ │     │                   │
└───────────────┘       │ │     │                   │
                        │ │     │                   │
                        │ │     │                   │
                        │ │     │                   │
                        │ │     │                   │
                        │ │     │                   │
                        │ │     └───────────────────┘
                        │ │
                        │ │
```

### State Broadcasts

The WomoLIN main unit broadcasts the state of its virtual devices periodically.
The frequency of the broadcast depends on the type of virtual device.
A state broadcast message should contain all states of the virtual device, including error codes.

# Open questions

* Device awaited by client, but state not broadcasted by any main unit: How to handle this?
* Talk about line termination in "Physical Layer"?
* Requesting state update from virtual device? May be needed if broadcasting frequency is too low. Could be write to id with no data.
