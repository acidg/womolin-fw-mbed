/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "VirtualDeviceBase.h"
#include "RelayDevice.h"
#include "DeviceStateUpdateManager.h"
#include "ControlBusManager"

#define BLINKING_RATE 500ms

template<typename T>

mainunit::VirtualDeviceBase<T> virtualDevices[] = {
		mainunit::RelayDevice { 1 }, // Light
		mainunit::RelayDevice { 2 }  // Pump
};

ControlBusManager controlBusManager{};
DeviceStateUpdateManager deviceStateUpdateManager{};

int main() {
	// Initialise the digital pin LED1 as an output
	DigitalOut led(SIGNAL_LED);

	// Setup CAN interface
	// Setup managers for hardware

	// Start scheduler for devices
	DeviceStateUpdateManager{}
}
