/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "VirtualDeviceBase.h"
#include "RelayDevice.h"

#define BLINKING_RATE 500ms

template<typename T>

mainunit::VirtualDeviceBase<T> virtualDevices[] = {
		mainunit::RelayDevice { 1 }
};

int main() {
	// Initialise the digital pin LED1 as an output
	DigitalOut led(SIGNAL_LED);

	AnalogIn test(ADC_TEMP);

	BufferedSerial uart_ctrl(USART1_TX_CTRL, USART1_RX_CTRL, 115200);

	while (true) {
		led = !led;
		uart_ctrl.write("Hello World!\n", 14);
		ThisThread::sleep_for(BLINKING_RATE);
	}
}
