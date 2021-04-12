#ifndef DEVICE_ICOMMAND_H_
#define DEVICE_ICOMMAND_H_

#include "ICommandParameter.h"

namespace mainunit {

/**
 * A command in the context of WomoLIN is an instruction which can be sent to the device
 * and triggers some routine on the device itself. This may result in change of
 * the states of the device.
 * A command does not directly return a result, but instead callers have to use the device's
 * states to check, whether the command was successful or failed and e.g. should be repeated.
 */
class ICommand {
public:
	virtual ~ICommand();

	/**
	 * Routine to execute when the command is triggered.
	 */
	virtual void run(ICommandParameter *parameters);
};
}

#endif
