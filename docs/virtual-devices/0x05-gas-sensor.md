# 0x05 Gas sensor

A Pressure, humidity, temperature and gas sensor (e.g. BME680).

## Status Data Format

| Data Byte in Message | Content                               |
| -------------------: | ------------------------------------- |
|                    0 | Virtual device type: always 0x05      |
|                 1..2 | Temperature in degree celsius x100    |
|                 3..6 | Pressure in Pascal                    |
|                7..10 | Humidity in % relative humidity x1000 |
|               11..14 | Gas resistance in Ohms                |

## Command Types

none
