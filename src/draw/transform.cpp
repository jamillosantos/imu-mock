/**
 * @author J. Santos <jamillo@gmail.com>
 * @date October 06, 2016
 */

#include "transform.h"

draw::TransformGuard::TransformGuard()
{
	glPushMatrix();
}

draw::TransformGuard::~TransformGuard()
{
	glPopMatrix();
}
