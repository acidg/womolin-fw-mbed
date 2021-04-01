# 0x04 Relay

A simple relay or switch which can be switched between SET and RESET state.

## Status Data Format

| Data Byte in Message | Type    | Content                                                                     |
| -------------------: | ------- | --------------------------------------------------------------------------- |
|                    0 | uint8_t | Virtual device type: always 0x04                                            |
|                    1 | uint8_t | 0x00: Relay/Switch is in SET state<br/>0x01: Relay/Switch is in RESET state |

## Command Types

### 0x04 SET/RESET

| Data Byte in Message | Type    | Content                                                   |
| -------------------: | ------- | --------------------------------------------------------- |
|                    0 | uint8_t | Command type: always 0x04                                 |
|                    1 | uint8_t | 0x00: Switch to SET state<br/>0x01: Switch to RESET state |
