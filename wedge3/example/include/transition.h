#ifndef TRANSITION_H
#define TRANSITION_H

#include <wedge2/main.h>
#include <wedge2/systems.h>

class Transition_Step : public wedge::Step
{
public:
	static const int LENGTH = 333;

	Transition_Step(bool out, wedge::Task *task); // in or out
	virtual ~Transition_Step();
	
	bool run();
	void draw();
	void start();

protected:
	bool out;
	Uint32 start_time;
};

#endif // TRANSITION_H
