#ifndef GUI_DRAWING_HOOK_H
#define GUI_DRAWING_HOOK_H

#include <wedge3/main.h>
#include <wedge3/systems.h>

class GUI_Drawing_Hook_Step : public wedge::Step
{
public:
	GUI_Drawing_Hook_Step(gui::GUI *gui, bool hook_draw_last);
	virtual ~GUI_Drawing_Hook_Step();

	void hook();
	void draw_fore();

private:
	gui::GUI *gui;
	bool hook_draw_last;
};

#endif // GUI_DRAWING_HOOK_H
