/**
 * @author J. Santos <jamillo@gmail.com>
 * @date October 06, 2016
 */

#include "colour.h"

draw::Colour draw::Colour::BLACK(0.0f, 0.0f, 0.0f);
draw::Colour draw::Colour::WHITE(1.0f, 1.0f, 1.0f);
draw::Colour draw::Colour::RED(1.0f, 0.0f, 0.0f);
draw::Colour draw::Colour::GREEN(0.0f, 1.0f, 0.0f);
draw::Colour draw::Colour::GREEN_ARMY(0.0f, 0.6f, 0.2f);
draw::Colour draw::Colour::BLUE(0.0f, 0.0f, 1.0f);
draw::Colour draw::Colour::YELLOW(1.0f, 1.0f, 0.0f);
draw::Colour draw::Colour::ORANGE(1.0f, 0.6f, 0.0f);
draw::Colour draw::Colour::PURPLE(0.5f, 0.0f, 0.5f);
draw::Colour draw::Colour::GRAY_LIGHT(0.8f, 0.8f, 0.8f);
draw::Colour draw::Colour::GRAY(0.4f, 0.4f, 0.4f);

draw::Colour::Colour(float r, float g, float b, float a)
	: _r(r), _g(g), _b(b), _a(a)
{ }

draw::Colour::Colour(float r, float g, float b)
	: Colour(r, g, b, 1.0f)
{ }

draw::Colour::Colour(const draw::Colour &&colour)
{
	*this = colour;
}

draw::Colour::Colour(const draw::Colour &colour)
{
	*this = colour;
}

draw::Colour::Colour(const draw::Colour *colour)
{
	*this = colour;
}

float draw::Colour::r() const
{
	return this->_r;
}

void draw::Colour::r(float r)
{
	this->_r = r;
}

float draw::Colour::g() const
{
	return this->_g;
}

void draw::Colour::g(float g)
{
	this->_g = g;
}

float draw::Colour::b() const
{
	return this->_b;
}

void draw::Colour::b(float b)
{
	this->_b = b;
}

float draw::Colour::a() const
{
	return this->_a;
}

void draw::Colour::a(float a)
{
	this->_a = a;
}

void draw::Colour::beginDraw()
{ }

void draw::Colour::draw()
{
	glColor4f(this->_r, this->_g, this->_b, this->_a);
}

void draw::Colour::endDraw()
{ }

bool draw::Colour::isInvalid()
{
	return false;
}

draw::Colour &draw::Colour::operator=(const draw::Colour *colour)
{
	this->_r = colour->_r;
	this->_g = colour->_g;
	this->_b = colour->_b;
	this->_a = colour->_a;
	return *this;
}

draw::Colour &draw::Colour::operator=(const draw::Colour &colour)
{
	this->_r = colour._r;
	this->_g = colour._g;
	this->_b = colour._b;
	this->_a = colour._a;
	return *this;
}

