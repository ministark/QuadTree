#pragma once
namespace Utils {
	class Rectangle 
	{
	private:
		float x_min, y_min, x_max, y_max;
	public:
		Rectangle();
		bool isInside(const Rectangle &);
		Rectangle(float, float, float, float);
		~Rectangle();
	};
}
