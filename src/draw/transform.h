#ifndef SIMULATION_TRANSFORM_HPP
#define SIMULATION_TRANSFORM_HPP

#include <GL/gl.h>

namespace draw
{
	/**
	 * Push and pop transformations.
	 */
	class TransformGuard
	{
	public:
		TransformGuard();

		~TransformGuard();
	};
}

#endif //SIMULATION_TRANSFORM_HPP
