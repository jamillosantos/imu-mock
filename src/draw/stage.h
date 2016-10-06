#ifndef SIMULATION_DRAW_STAGE_HPP
#define SIMULATION_DRAW_STAGE_HPP

#include "drawable.h"

#include <vector>

namespace draw
{
	class Stage
	{
	protected:
		std::vector<Drawable*> objects;
	public:
		virtual void draw();

		virtual void add(Drawable *drawable);
	};
}

#endif //SIMULATION_STAGE_HPP
