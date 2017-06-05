#include "Rectangle.h"
using namespace Utils;

Utils::Rectangle::Rectangle()
{
}

bool Utils::Rectangle::isInside(const Rectangle &rect)
{
	if (rect.x_max <= x_max && rect.y_max <= y_max && rect.x_min <= x_min && rect.y_min <= y_min)
		return true;
	else
		return false;
}

Rectangle::Rectangle(float min_x, float min_y, float max_x, float max_y)
{
	x_min = min_x;  y_min = min_y;
	x_max = max_x;	y_max = max_y;

}

Rectangle::~Rectangle()
{
}
