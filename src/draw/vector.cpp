/**
 * @author J. Santos <jamillo@gmail.com>
 * @date October 06, 2016
 */

#include "vector.h"

draw::Vector3f::Vector3f(float x, float y, float z)
	: Vector3<float>(x, y, z), _dirty(false)
{ }

draw::Vector3f::Vector3f(float value)
	: Vector3f(value, value, value)
{ }

draw::Vector3f::Vector3f() :
	Vector3f(0)
{ }

bool draw::Vector3f::isDirty()
{
	return this->_dirty;
}

void draw::Vector3f::clean()
{
	this->_dirty = false;
}

void draw::Vector3f::xyz(float x, float y, float z)
{
	this->_dirty = (this->x() != x) || (this->y() != y) || (this->z() != z);
	data::Vector3<float>::xyz(x, y, z);
}

void draw::Vector3f::xyz(float value)
{
	this->_dirty = (this->x() != value) || (this->y() != value) || (this->z() != value);
	data::Vector3<float>::xyz(value);
}

void draw::Vector3f::x(float value)
{
	this->_dirty = (this->x() != value);
	data::Vector3<float>::x(value);
}

void draw::Vector3f::y(float value)
{
	this->_dirty = (this->y() != value);
	data::Vector3<float>::y(value);
}

void draw::Vector3f::z(float value)
{
	this->_dirty = (this->z() != value);
	data::Vector3<float>::z(value);
}

float draw::Vector3f::x()
{
	return data::Vector3<float>::x();
}

float draw::Vector3f::y()
{
	return data::Vector3<float>::y();
}

float draw::Vector3f::z()
{
	return data::Vector3<float>::z();
}
