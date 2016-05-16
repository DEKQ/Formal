#include "Control.hpp"

void dekq::formal::Control::setWidth(int width)
{
	properties.width = width;
	updateComponents();
}

int dekq::formal::Control::getWidth()
{
	return properties.width;
}

void dekq::formal::Control::setHeight(int height)
{
	properties.height = height;
	updateComponents();
}

int dekq::formal::Control::getHeight()
{
	return properties.height;
}

void dekq::formal::Control::setX(int x)
{
	properties.x = x;
}

int dekq::formal::Control::getX()
{
	return properties.x;
}

void dekq::formal::Control::setY(int y)
{
	properties.y = y;
	updateComponents();
}

int dekq::formal::Control::getY()
{
	return properties.y;
}
