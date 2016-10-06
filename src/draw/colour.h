/**
 * @author J. Santos <jamillo@gmail.com>
 * @date November 25, 2015
 **/

#ifndef VISUALIZER_DRAW_COLOUR_HPP
#define VISUALIZER_DRAW_COLOUR_HPP

#include "drawable.h"

namespace draw
{
class Colour
	: public Drawable
{
public:
	static Colour BLACK;
	static Colour WHITE;
	static Colour RED;
	static Colour GREEN;
	static Colour GREEN_ARMY;
	static Colour BLUE;
	static Colour YELLOW;
	static Colour ORANGE;
	static Colour PURPLE;
	static Colour GRAY_LIGHT;
	static Colour GRAY;

private:
	float _r;
	float _g;
	float _b;
	float _a;
public:
	Colour(float r, float g, float b, float a);

	Colour(float r, float g, float b);

	Colour(const Colour &&colour);

	Colour(const Colour &colour);

	Colour(const Colour *colour);

	float r() const;

	void r(float r);

	float g() const;

	void g(float g);

	float b() const;

	void b(float b);

	float a() const;

	void a(float a);

	virtual void beginDraw();

	virtual void draw();

	virtual void endDraw();

	virtual bool isInvalid();

	Colour &operator=(const Colour *colour);

	Colour &operator=(const Colour &colour);
};
}

#endif //VISUALIZER_DRAW_COLOUR_HPP
