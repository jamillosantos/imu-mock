/**
 * @author J. Santos <jamillo@gmail.com>
 * @date November 25, 2015
 **/

#ifndef VISUALIZER_ELEMENTS_CUBE_HPP
#define VISUALIZER_ELEMENTS_CUBE_HPP

#include "../draw/drawable.h"
#include "../draw/colour.h"

namespace elements
{

class CubeColours
{
private:
	draw::Colour _top;
	draw::Colour _bottom;
	draw::Colour _left;
	draw::Colour _right;
	draw::Colour _front;
	draw::Colour _back;
public:
	CubeColours();

	draw::Colour &top();

	void top(draw::Colour &top);

	draw::Colour &bottom();

	void bottom(draw::Colour &bottom);

	draw::Colour &left();

	void left(draw::Colour &left);

	draw::Colour &right();

	void right(draw::Colour &right);

	draw::Colour &front();

	void front(draw::Colour &front);

	draw::Colour &back();

	void back(draw::Colour &back);

	void colour(const draw::Colour &colour);
};

class Cube
	: public draw::DrawableObject
{
private:
	static draw::Colour lineColour;

	CubeColours _colour;
public:
	virtual void draw() override;

	CubeColours &colour();
};
}

#endif //VISUALIZER_ELEMENTS_CUBE_HPP
