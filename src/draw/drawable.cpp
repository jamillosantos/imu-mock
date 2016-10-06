/**
 * @author J. Santos <jamillo@gmail.com>
 * @date October 06, 2016
 */

#include "drawable.h"

void draw::DrawableObject::applyTransformation()
{
	glPushMatrix();
	glTranslatef(this->_position.x(), this->_position.y(), this->_position.z());
	glPushMatrix();
	if (this->_rotate.x() != 0.0f)
		glRotatef(R2D(this->_rotate.x()), 1.0f, 0.0f, 0.0f);

	if (this->_rotate.y() != 0.0f)
		glRotatef(R2D(this->_rotate.y()), 0.0f, 1.0f, 0.0f);

	if (this->_rotate.z() != 0.0f)
		glRotatef(R2D(this->_rotate.z()), 0.0f, 0.0f, 1.0f);
}

void draw::DrawableObject::unapplyTransformation()
{
	glPopMatrix();
	glPopMatrix();
}

draw::DrawableObject::DrawableObject()
	: _absolute(false), _size(1.0f)
{ }

bool draw::DrawableObject::isAbsolute()
{
	return this->_absolute;
}

draw::Vector3f &draw::DrawableObject::position()
{
	return this->_position;
}

void draw::DrawableObject::position(const draw::Vector3f &position)
{
	this->_position = position;
}

draw::Vector3f &draw::DrawableObject::rotate()
{
	return this->_rotate;
}

void draw::DrawableObject::rotate(const draw::Vector3f &rotate)
{
	this->_rotate = rotate;
}

draw::Vector3f &draw::DrawableObject::size()
{
	return this->_size;
}

void draw::DrawableObject::size(const draw::Vector3f &size)
{
	this->_size = size;
}

draw::Vector3f &draw::DrawableObject::center()
{
	return this->_center;
}

void draw::DrawableObject::center(const draw::Vector3f &center)
{
	this->_center = center;
}

void draw::DrawableObject::beginDraw()
{
	this->applyTransformation();

	// Changes the center before the translation.
	glTranslatef(this->_size.x() * this->_center.x(), this->_size.y() * this->_center.y(), this->_size.z() * this->_center.z());
	glPushMatrix();
	glScalef(this->_size.x(), this->_size.y(), this->_size.z());
}

void draw::DrawableObject::endDraw()
{
	this->unapplyTransformation();
	glPopMatrix();
}

bool draw::DrawableObject::isInvalid()
{
	return false;
}
