#include <iostream>
#include "QuadTree.h"

class foo {
	int x;
};
int main() {
	Utils::Rectangle rect1(0,0,10,10);
	Utils::Rectangle rect2(1, 1, 5, 5);

	Utils::QuadTree qtree(0, rect1);
	qtree.clear();
	std::cout << rect1.isInside(rect2) << std::endl;
	system("pause");
}
