#pragma once
namespace Utils {
	class Rectangle 
	{
	public:
		float x_min, y_min, x_max, y_max;
		bool isInside(const Rectangle &);
		Rectangle();
		Rectangle(float, float, float, float);
		~Rectangle();
	};
}
