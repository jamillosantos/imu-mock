
#ifndef SIMULATION_DRAWNABLE_HPP
#define SIMULATION_DRAWNABLE_HPP

#include <GL/gl.h>

#include "vector.h"
#include "transform.h"
#include "value.h"
#include "../definitions.h"

namespace draw
{
	class Drawable
	{
	public:
		virtual void beginDraw() = 0;
		virtual void draw() = 0;
		virtual void endDraw() = 0;

		virtual bool isInvalid() = 0;
	};

	class DrawableObject
		: public Drawable
	{
	protected:
		bool _absolute;

		Vector3f _position;
		Vector3f _rotate;
		Vector3f _size;
		Vector3f _center;

		virtual void applyTransformation();

		virtual void unapplyTransformation();
	public:
		DrawableObject();

		virtual bool isAbsolute();

		virtual Vector3f &position();

		virtual void position(const Vector3f &position);

		virtual Vector3f &rotate();

		virtual void rotate(const Vector3f &rotate);

		virtual Vector3f &size();

		virtual void size(const Vector3f &size);

		virtual Vector3f &center();

		virtual void center(const Vector3f &center);

		virtual void beginDraw() override;

		virtual void endDraw() override;

		virtual bool isInvalid() override;
	};
}

#endif //SIMULATION_DRAWNABLE_HPP
