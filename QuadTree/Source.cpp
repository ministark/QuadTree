#include <iostream>
#include "QuadTree.h"

class foo {
	int x;
};
int main() {
	Utils::Rectangle rect(10,10,10,10);
	Utils::QuadTree qtree(0, rect);
	qtree.clear();
	std::cout << "Hello" << std::endl;
	system("pause");
}
