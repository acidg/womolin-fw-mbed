#ifndef DEVICESTATEUPDATEMANAGER_H_
#define DEVICESTATEUPDATEMANAGER_H_

#include <Callback.h>

namespace mainunit {

/**
 * Manager thread taking care to schedule state updates of the configured devices.
 */
class DeviceStateUpdateManager {
public:
	DeviceStateUpdateManager();
	virtual ~DeviceStateUpdateManager();
	virtual void run();
	void stop();
private:
	bool interrupted = false;
};

} /* namespace mainunit */

#endif /* DEVICESTATEUPDATEMANAGER_H_ */
