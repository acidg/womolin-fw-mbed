/*
 * DeviceStateUpdateManager.cpp
 *
 *  Created on: 15.04.2021
 *      Author: bene
 */

#include <DeviceStateUpdateManager.h>

namespace mainunit {

DeviceStateUpdateManager::DeviceStateUpdateManager() {
	// TODO Auto-generated constructor stub

}

DeviceStateUpdateManager::~DeviceStateUpdateManager() {
	// TODO Auto-generated destructor stub
}

void DeviceStateUpdateManager::run() {
	while (!interrupted) {
		// iterate over all devices and pull the states
	}
}

void DeviceStateUpdateManager::stop() {
	this->interrupted = true;
}

} /* namespace mainunit */
