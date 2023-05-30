#ifndef WEDGE3_SLIDE_ENTITY_OFFSET_H
#define WEDGE3_SLIDE_ENTITY_OFFSET_H

#include "wedge3/main.h"
#include "wedge3/systems.h"

namespace wedge {

class Map_Entity;

class WEDGE3_EXPORT Slide_Entity_Offset_Step : public Step
{
public:
	Slide_Entity_Offset_Step(Map_Entity *entity, util::Point<float> destination_offset, float speed/* pixels per tick along line */, Task *task);
	virtual ~Slide_Entity_Offset_Step();

	void start();
	bool run();

private:
	Map_Entity *entity;
	util::Point<float> destination_offset;
	int count;
	float inc_x;
	float inc_y;
};

}

#endif // WEDGE3_SLIDE_ENTITY_OFFSET_H
