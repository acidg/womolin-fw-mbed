#include "VirtualDeviceBase.h"

namespace mainunit {

template<typename T> VirtualDeviceBase<T>::VirtualDeviceBase(T *state, ICommand *commands) {
	this->state = state;
	this->commands = commands;
}

template<typename T> void VirtualDeviceBase<T>::executeCommand(unsigned char commandType,
		ICommandParameter parameters) {
	// TODO find command in list of commands and execute it
}
}
