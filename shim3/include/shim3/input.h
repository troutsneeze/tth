#ifndef NOO_INPUT_H
#define NOO_INPUT_H

#include "shim3/main.h"
#include "shim3/steamworks.h"

namespace noo {

namespace input {

struct SHIM3_EXPORT Focus_Event : public TGUI_Event {
	TGUI_Event_Type orig_type;
	union {
		TGUI_Event::TGUI_Event_Keyboard orig_keyboard;
		TGUI_Event::TGUI_Event_Joystick orig_joystick;
	} u;

	virtual ~Focus_Event();
};

bool start();
void reset();
void end();
void update();
void handle_event(TGUI_Event *event);

bool SHIM3_EXPORT convert_to_focus_event(TGUI_Event *event, Focus_Event *focus);
void SHIM3_EXPORT convert_focus_to_original(TGUI_Event *event);
void SHIM3_EXPORT rumble(Uint32 length);
bool SHIM3_EXPORT is_joystick_connected();
std::string SHIM3_EXPORT get_joystick_button_name(int button);
std::string SHIM3_EXPORT get_joystick_button_colour_code(int button);
void SHIM3_EXPORT drop_repeats(bool joystick = true, bool mouse = true);
SDL_JoystickID SHIM3_EXPORT get_controller_id();

#ifdef STEAMWORKS
ControllerHandle_t SHIM3_EXPORT get_controller_handle();
#endif

bool SHIM3_EXPORT system_has_touchscreen();
bool SHIM3_EXPORT system_has_keyboard();

} // End namespace input

} // End namespace noo

#endif // NOO_INPUT_H
