# 0x07 Truma Combi E Heater

Truma Combi E heaters with boiler and integrated electrical heating element. 

## Status Data Format

| Data Byte in Message | Type    | Content                                                                        |
| -------------------: | ------- | ------------------------------------------------------------------------------ |
|                    0 | uint8_t | Virtual device type: always 0x07                                               |
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
