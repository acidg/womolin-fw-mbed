# 0x06 Planar/Autoterm Air 2/4D diesel heater

Planar/Autoterm Air 2/4D diesel heater. The heater inteface provides the following modes:

- OFF: The heater is turned off
- HEATING_BY_TEMP: The heater is turned on (heating) and will try to reach the configured target temperature
- HEATING_BY_POWER: The heater is turned on (heating) and will heat with the configured power level (0-9)
- VENTING: The heater's ventilation is turned on and will ventilate with the configured power level (0-9)

If there was an error when executing a command, the error field of the status broadcast message will be non-zero and can be cleared by triggering a new command.

## Status Data Format

| Data Byte in Message | Type    | Content                                                                        |
| -------------------: | ------- | ------------------------------------------------------------------------------ |
|                    0 | uint8_t | Virtual device type: always 0x06                                               |
|                    1 | uint8_t | Mode:<br/>0: OFF<br/>1: HEATING_BY_TEMP<br/>2: HEATING_BY_POWER<br/>3: VENTING |
|                    2 | uint8_t | Target Temperature in degree celsius (0-30°C)                                  |
|                    3 | uint8_t | Target Ventilation speed/Heating Power (0-9)                                   |
|                    4 | int8_t  | Current measured temperature in degree celsius (can be negative)               |
|                    5 | uint8_t | Error code                                                                     |

## Command Types

### 0x04 Switch Mode

| Data Byte in Message | Type    | Content                                                                        |
| -------------------: | ------- | ------------------------------------------------------------------------------ |
|                    0 | uint8_t | Command type: always 0x04                                                      |
|                    1 | uint8_t | Mode:<br/>0: OFF<br/>1: HEATING_BY_TEMP<br/>2: HEATING_BY_POWER<br/>3: VENTING |
|                    2 | uint8_t | Target Temperature in degree celsius (0-30°C)                                  |
|                    3 | uint8_t | Ventilation speed/Heating Power (0-9)                                          |
