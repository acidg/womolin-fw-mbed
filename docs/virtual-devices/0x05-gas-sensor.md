# 0x05 Gas sensor

A Pressure, humidity, temperature and gas sensor (e.g. BME680).

## Status Data Format

| Data Byte in Message | Type     | Content                               |
| -------------------: | -------- | ------------------------------------- |
|                    0 | uint8_t  | Virtual device type: always 0x05      |
|                 1..2 | int16_t  | Temperature in degree celsius x100    |
|                 3..6 | uint32_t | Pressure in Pascal                    |
|                7..10 | uint32_t | Humidity in % relative humidity x1000 |
|               11..14 | uint32_t | Gas resistance in Ohms                |

## Command Types

none
