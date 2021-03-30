# WomoLIN Protocol

This document describes the protocol used for exchange of data between client devices and the WomoLIN main unit(s).

## History

| Version | Changes                     |
| ------- | --------------------------- |
| v1.0    | First draft of the protocol |

# Physical Layer

The WomoLIN protocol is based on CAN bus with 11-bit message identifiers (CAN 2.0A).

# Software Layer

There are two kind of messages on the bus:

- state broadcasts
- commands

A virtual device in the context of the WomoLIN protocol is an endpoint of the WomoLIN network which periodically sends out its state and provides an interface to trigger commands.
Virtual devices are the interface to physical devices and take care of the protocol needed to communicate with the physical device.

```
                      CAN Bus
                        H L
                        │ │     ┌───────────────────┐
                        │ │     │ WomoLIN Main Unit │
┌───────────────┐       │ │     │                   │
│ Client        ├───────┼─┤     │ ┌───────────────┐ │  ┌──────────────────┐
| Display Unit 1|       | ├─────┼─┤ Virtual Device| |  | Physical Device  |
│               │───────┤ |     | | Heater        ├─┼──┤                  │
└───────────────┘       ├─┼─────┼─┤ ID: 0x0F1     │ │  │ Diesel Heater    │
                        │ │     │ └───────────────┘ │  └──────────────────┘
┌───────────────┐       │ │     │                   │
│ Client        ├───────┼─┤     │ ┌───────────────┐ │  ┌──────────────────┐
│ Display Unit 2│       │ ├─────┼─┤ Virtual Device│ │  │ Physical Device  │
│               ├───────┤ │     │ │ Water Tank    ├─┼──┤                  │
└───────────────┘       ├─┼─────┼─┤ ID: 0x004     │ │  │ Water Tank Sensor│
                        │ │     │ └───────────────┘ │  └──────────────────┘
┌───────────────┐       │ │     │         .         │
│ Client        ├───────┼─┤     │         .         │
│ Tank Monitor  │       │ │     │         .         │
│               ├───────┤ │     │                   │
└───────────────┘       │ │     │                   │
                        │ │     └───────────────────┘
                        │ │
```

_Fig.1: Overview of the WomoLIN protocol architecture_

## Message IDs

Each virtual device (i.e. endpoint) uses a unique 10-bit identifier (id).
This id is used by the main unit to broadcast the virtual device's state and by the clients to trigger commands.
The CAN bus protocol prioritizes messages with higher id.
In order to be prioritize commands on the bus, the id for command messages has to be higher than for state broadcasts.

Therefore, command messages have the MSB (11th bit of the CAN message identifier) of the id set to 1, whereas state broadcast must have the MSB set to 0.
This ensures that commands are always prioritized on the bus and makes it easier for the main unit to identify commands.

The other 10 bits of the id are unique for each virtual device configured on the WomoLIN board and are chosen by the user.
If multiple virtual devices of the same type are configured (e.g. two tank sensors), the ids used for messages have to be different.

**Example:** Using the ids from _Fig.1_, a state broadcast of the virtual device with name "Heater" would be 0x0F1, whereas a command message targeting the virtual device would be 0x5F1.

## State Broadcast Messages

The WomoLIN main unit broadcasts the state of each configured virtual device (VD) periodically using state broadcast messages.
The frequency of the state broadcast messages depend on the type of virtual device.
A state broadcast message must contain all states of the virtual device, including error codes.
The message id of the state broadcast has to be unique for each virtual device.
The data of the state broadcast message starts with the type id of the virtual device.
The 2 least significant bits of the type id are reserved.
Therefore virtual device type ids start from 0x04.

| **Field**       | Msg Identifier  | Data Byte 0  | Data Bytes 1..n       |
| --------------- | --------------- | ------------ | --------------------- |
| **Description** | `0x000` + VD ID | VD type      | states of the VD      |
| **Pos. values** | `0x401..0x5FF`  | `0x05..0xFF` | `0x00..0xFF` for each |

_Table.1: Fields of a state broadcast message_

## Command Messages

If a client wants to trigger a command on a virtual device (VD), it writes a command message on the bus.
The message ids of command messages always have their MSB set to 1 in order to be prioritized and easily recognized by the main unit(s).
The message id of the command message has to be unique for each virtual device.
The first byte of the data refers to the type of the command for the virtual device.
The 2 least significant bits of the type are reserved.
Therefore, the lowest command type for a virtual device is 0x05.

| **Field**       | Msg Identifier  | Data Byte 0  | Data Bytes 1..n        |
| --------------- | --------------- | ------------ | ---------------------- |
| **Description** | `0x400` + VD ID | command type | parameters for command |
| **Pos. values** | `0x401..0x5FF`  | `0x05..0xFF` | `0x00..0xFF` for each  |

_Table.2: Fields of a command message_

# Open questions

- Device awaited by client, but state not broadcasted by any main unit: How to handle this?
- Talk about line termination in "Physical Layer"?
- Requesting state update from virtual device? May be needed if broadcasting frequency is too low. Could be write to id with no data.
- Acknowledge command messages?
