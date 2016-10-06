/**
 * @author J. Santos <jamillo@gmail.com>
 * @date October 06, 2016
 */

#include "stage.h"

void draw::Stage::draw()
{
	for (Drawable *drawable : this->objects)
	{
		drawable->beginDraw();
		drawable->draw();
		drawable->endDraw();
	}
}

void draw::Stage::add(draw::Drawable *drawable)
{
	this->objects.push_back(drawable);
}
