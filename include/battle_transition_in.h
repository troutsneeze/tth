#ifndef BATTLE_TRANSITION_IN_H
#define BATTLE_TRANSITION_IN_H

#include <wedge3/main.h>
#include <wedge3/systems.h>

#include "battle_game.h"
#include "transition.h"

class Battle_Transition_In_Step : public Transition_Step
{
public:
	Battle_Transition_In_Step(wedge::Battle_Game *battle_game, wedge::Task *task);
	virtual ~Battle_Transition_In_Step();

	void start();
	bool run();

private:
	wedge::Battle_Game *battle_game;
};

#endif // BATTLE_TRANSITION_IN_H
