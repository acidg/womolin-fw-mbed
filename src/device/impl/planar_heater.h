#ifndef PLANAR_HEATER_H
#define PLANAR_HEATER_H

#define PLANAR_VIRTUAL_DEVICE_TYPE 0x06

enum EPlanarMode
{
    OFF = 0,
    HEATING_BY_TEMP = 1,
    HEATING_BY_POWER = 2,
    VENTING = 3
}

typedef struct
{
    EPlanarMode mode;
    uint8_t target_temperature;
    uint8_t power_level;
    int8_t current_temperature;
    uint8_t error_code;
} PlanarStatus_t;

VirtualDevice_t create_planar_vd(uint8_t id)
{
    VirtualDevice_t planar_device = {
        id,
        
    };
    return planar_device;
}

#endif