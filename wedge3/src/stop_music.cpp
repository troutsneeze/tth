#include "wedge3/map_entity.h"
#include "wedge3/stop_music.h"

using namespace wedge;

namespace wedge {

Stop_Music_Step::Stop_Music_Step(Task *task) :
	Step(task)
{
}

Stop_Music_Step::~Stop_Music_Step()
{
}

void Stop_Music_Step::start()
{
	audio::stop_music();
}

bool Stop_Music_Step::run()
{
	send_done_signal();
	return false;
}

}
