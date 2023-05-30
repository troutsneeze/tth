#ifndef NOO_TRIGGER_H
#define NOO_TRIGGER_H

#include "shim3/main.h"

namespace noo {

namespace util {

class SHIM3_EXPORT Trigger {
public:
	virtual void run() = 0;
};

} // End namespace util

} // End namespace noo

#endif // NOO_TRIGGER_H
