/**
 * @author J. Santos <jamillo@gmail.com>
 * @date October 06, 2016
 */

#include "cube.h"

draw::Colour elements::Cube::lineColour(1.0f, 1.0f, 1.0f, 0.6f);

elements::CubeColours::CubeColours() :
	_top(draw::Colour::RED), _bottom(draw::Colour::ORANGE), _left(draw::Colour::YELLOW),
	_right(draw::Colour::WHITE), _front(draw::Colour::BLUE), _back(draw::Colour::GREEN)
{ }

draw::Colour &elements::CubeColours::top()
{
	return this->_top;
}

void elements::CubeColours::top(draw::Colour &top)
{
	this->_top = top;
}

draw::Colour &elements::CubeColours::bottom()
{
	return this->_bottom;
}

void elements::CubeColours::bottom(draw::Colour &bottom)
{
	this->_bottom = bottom;
}

draw::Colour &elements::CubeColours::left()
{
	return this->_left;
}

void elements::CubeColours::left(draw::Colour &left)
{
	this->_left = left;
}

draw::Colour &elements::CubeColours::right()
{
	return this->_right;
}

void elements::CubeColours::right(draw::Colour &right)
{
	this->_right = right;
}

draw::Colour &elements::CubeColours::front()
{
	return this->_front;
}

void elements::CubeColours::front(draw::Colour &front)
{
	this->_front = front;
}

draw::Colour &elements::CubeColours::back()
{
	return this->_back;
}

void elements::CubeColours::back(draw::Colour &back)
{
	this->_back = back;
}

void elements::CubeColours::colour(const draw::Colour &colour)
{
	this->_top = colour;
	this->_bottom = colour;
	this->_left = colour;
	this->_right = colour;
	this->_front = colour;
	this->_back = colour;
}

void elements::Cube::draw()
{
	glBegin(GL_QUADS);
	// Top
	this->_colour.top().draw();
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f,  0.5f, -0.5f);
	glVertex3f( 0.5f,  0.5f, -0.5f);
	glVertex3f( 0.5f, -0.5f, -0.5f);
	// Bottom
	this->_colour.bottom().draw();
	glVertex3f(-0.5f, -0.5f,  0.5f);
	glVertex3f(-0.5f,  0.5f,  0.5f);
	glVertex3f( 0.5f,  0.5f,  0.5f);
	glVertex3f( 0.5f, -0.5f,  0.5f);
	// Left
	this->_colour.left().draw();
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f,  0.5f, -0.5f);
	glVertex3f(-0.5f,  0.5f,  0.5f);
	glVertex3f(-0.5f, -0.5f,  0.5f);
	// Right
	this->_colour.right().draw();
	glVertex3f( 0.5f, -0.5f, -0.5f);
	glVertex3f( 0.5f,  0.5f, -0.5f);
	glVertex3f( 0.5f,  0.5f,  0.5f);
	glVertex3f( 0.5f, -0.5f,  0.5f);
	// Front
	this->_colour.front().draw();
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f( 0.5f, -0.5f, -0.5f);
	glVertex3f( 0.5f, -0.5f,  0.5f);
	glVertex3f(-0.5f, -0.5f,  0.5f);
	// Back
	this->_colour.back().draw();
	glVertex3f(-0.5f,  0.5f, -0.5f);
	glVertex3f( 0.5f,  0.5f, -0.5f);
	glVertex3f( 0.5f,  0.5f,  0.5f);
	glVertex3f(-0.5f,  0.5f,  0.5f);
	glEnd();

	// Draws the line contour of the cube.
	glBegin(GL_LINES);
	lineColour.draw();
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f,  0.5f, -0.5f);
	glVertex3f( 0.5f,  0.5f, -0.5f);
	glVertex3f( 0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f, -0.5f,  0.5f);
	glVertex3f(-0.5f,  0.5f,  0.5f);
	glVertex3f( 0.5f,  0.5f,  0.5f);
	glVertex3f( 0.5f, -0.5f,  0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f,  0.5f, -0.5f);
	glVertex3f(-0.5f,  0.5f,  0.5f);
	glVertex3f(-0.5f, -0.5f,  0.5f);
	glVertex3f( 0.5f, -0.5f, -0.5f);
	glVertex3f( 0.5f,  0.5f, -0.5f);
	glVertex3f( 0.5f,  0.5f,  0.5f);
	glVertex3f( 0.5f, -0.5f,  0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f( 0.5f, -0.5f, -0.5f);
	glVertex3f( 0.5f, -0.5f,  0.5f);
	glVertex3f(-0.5f, -0.5f,  0.5f);
	glVertex3f(-0.5f,  0.5f, -0.5f);
	glVertex3f( 0.5f,  0.5f, -0.5f);
	glVertex3f( 0.5f,  0.5f,  0.5f);
	glVertex3f(-0.5f,  0.5f,  0.5f);
	glEnd();
}

elements::CubeColours &elements::Cube::colour()
{
	return this->_colour;
}