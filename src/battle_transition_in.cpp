#include <wedge3/general.h>
#include <wedge3/globals.h>

#include "battle_game.h"
#include "battle_transition_in.h"
#include "battle_transition_in2.h"
#include "transition.h"

Battle_Transition_In_Step::Battle_Transition_In_Step(wedge::Battle_Game *battle_game, wedge::Task *task) :
	Transition_Step(true, task),
	battle_game(battle_game)
{
}

Battle_Transition_In_Step::~Battle_Transition_In_Step()
{
}

void Battle_Transition_In_Step::start()
{
	Transition_Step::start();

	audio::stop_music();
	TTH_GLOBALS->battle_start->play(false);
}

bool Battle_Transition_In_Step::run()
{
	bool ret = Transition_Step::run();
	if (ret == false) {
		BATTLE = battle_game;
		BATTLE->start();
		NEW_SYSTEM_AND_TASK(BATTLE)
		Battle_Transition_In2_Step *step = new Battle_Transition_In2_Step(new_task);
		ADD_STEP(step)
		ADD_TASK(new_task)
		FINISH_SYSTEM(BATTLE)
	}
	return ret;
}
