#include "QuadTree.h"
using namespace Utils;

Utils::QuadTree::QuadTree()
{
}

QuadTree::QuadTree(int lvl, Rectangle pbounds)
{
	level = lvl; bounds = pbounds;

	for (size_t i = 0; i < 4; i++)
		nodes[i] = NULL;
}

void Utils::QuadTree::clear()
{
	for (size_t i = 0; i < 4; i++)
	{
		 if (nodes[i] != nullptr)nodes[i]->clear();
	}
	objects.clear();
	std::cout << "Clearing level - " << level << std::endl;
}

void QuadTree::setMaxObjects(int obj)
{
	max_objects = obj;
}

void QuadTree::setMaxLevels(int lvl)
{
	max_levels = lvl;
}

QuadTree::~QuadTree()
{
}

//template class QuadTree<int>;