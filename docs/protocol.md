# WomoLIN Protocol

This document describes the protocol used for exchange of data between client devices and the WomoLIN main unit(s).

## History

| Version | Changes                     |
| ------- | --------------------------- |
| v1.0    | First draft of the protocol |

## Physical Layer

The WomoLIN protocol is based on CAN bus with 11-bit message identifiers (CAN 2.0A).

## Software Layer

There are two kinds of messages on the bus:

- state broadcasts
- commands

A virtual device (VD) in the context of the WomoLIN protocol is an endpoint of the WomoLIN network which periodically sends out its state and provides an interface to trigger commands.
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
└───────────────┘       ├─┼─────┼─┤ VD-ID: 0xF1   │ │  │ Diesel Heater    │
                        │ │     │ └───────────────┘ │  └──────────────────┘
┌───────────────┐       │ │     │                   │
│ Client        ├───────┼─┤     │ ┌───────────────┐ │  ┌──────────────────┐
│ Display Unit 2│       │ ├─────┼─┤ Virtual Device│ │  │ Physical Device  │
│               ├───────┤ │     │ │ Water Tank    ├─┼──┤                  │
└───────────────┘       ├─┼─────┼─┤ VD-ID: 0x05   │ │  │ Water Tank Sensor│
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

### Message IDs

Each virtual device (i.e. endpoint) configured on the WomoLIN main unit has a unique 8-bit identifier (VD-ID).
This identifier is used by the main unit to broadcast the virtual devices' states and by clients to trigger commands of a virtual device.
The VD-IDs are chosen by the user during configuration of the WomoLIN main unit.
If multiple virtual devices of the same type are configured (e.g. two tank sensors), the IDs must be different.

The CAN bus protocol uses messages with 11-bit message identifiers.
The protocol prioritizes messages with higher message ID.
In order to prioritize command messages on the bus, the message ID for command messages has to be higher than for state broadcast messages.

Therefore, WomoLIN uses CAN bus message identifiers in the following format:

Command messages have the MSB of the CAN message identifier set to 1, whereas state broadcast must have the MSB set to 0.
The next two bits are reserved.
The remaining 8 bits of the CAN message identifier are set to the ID of the virtual device, which is source of the states in a state broadcast message, or target of the command message sent by a client.
This ensures that commands are always prioritized on the bus and makes it easier for the main unit to identify commands.

| **Bit (MSB to LSB)** | 10                                                    | 9..8     | 7..0  |
| -------------------- | ----------------------------------------------------- | -------- | ----- |
| **Description**      | `0` for state broadcasts<br/>`1` for command messages | reserved | VD-ID |

**Example:** Using the VD-IDs from _Fig.1_, a state broadcast of the virtual device with name "Heater" would be 0x0F1, whereas the message ID of a command message targeting the virtual device would be 0x5F1.

### State Broadcast Messages

The WomoLIN main unit broadcasts the state of each configured virtual device (VD) periodically using state broadcast messages.
The frequency of the state broadcast messages depend on the type of virtual device.
A state broadcast message must contain all states of the virtual device, including error codes.
The message ID of the state broadcast has to be unique for each virtual device.
The data of the state broadcast message starts with the type of the virtual device (see [available virtual device types](virtual-devices/README.md)).
The 2 least significant bits of the type are reserved.
Therefore, the lowest virtual device type is 0x04.

| **Field**       | Msg Identifier  | Data Byte 0  | Data Bytes 1..n       |
| --------------- | --------------- | ------------ | --------------------- |
| **Description** | `0x000` + VD-ID | VD type      | states of the VD      |
| **Pos. values** | `0x001..0x3FF`  | `0x04..0xFF` | `0x00..0xFF` for each |

_Table.1: Fields of a state broadcast message_

### Command Messages

If a client wants to trigger a command on a virtual device (VD), it writes a command message on the bus.
The message IDs of command messages always have their MSB set to 1 in order to be prioritized and easily recognized by the main unit(s).
The message ID of the command message has to be unique for each virtual device.
The first byte of the data refers to the type of the command for the virtual device.
The 2 least significant bits of the type are reserved.
Therefore, the lowest command type for a virtual device is 0x04.

| **Field**       | Msg Identifier  | Data Byte 0  | Data Bytes 1..n        |
| --------------- | --------------- | ------------ | ---------------------- |
| **Description** | `0x400` + VD-ID | command type | parameters for command |
| **Pos. values** | `0x401..0x4FF`  | `0x04..0xFF` | `0x00..0xFF` for each  |

_Table.2: Fields of a command message_

## Open questions

- Device awaited by client, but state not broadcasted by any main unit: How to handle this?
- Talk about line termination in "Physical Layer"?
- Requesting state update from virtual device? May be needed if broadcasting frequency is too low. Could be write to ID with no data.
- Acknowledge command messages?
