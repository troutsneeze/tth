#ifndef QUESTION_H
#define QUESTION_H

#include <wedge3/systems.h>

#include "dialogue.h"

class Question_Step : public wedge::Step
{
public:
	Question_Step(std::vector<std::string> choices, int escape_choice, wedge::Task *task);
	virtual ~Question_Step();

	bool run();
	void done_signal(wedge::Step *step);

	int get_choice();
	void set_choice(int choice);

private:
	int choice;
	std::vector<std::string> choices;
	Dialogue_Step *dialogue_step;
	bool done;
	int escape_choice;
};

#endif // QUESTION_H
