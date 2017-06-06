#include "QuadTree.h"
using namespace Utils;

void Utils::QuadTree::split()
{
	float centerx_ = (bounds.x_min + bounds.x_max) / 2;
	float centery_ = (bounds.y_min + bounds.y_max) / 2;
	
	Rectangle q1(centerx_, centery_, bounds.x_max, bounds.y_max);
	Rectangle q2(centerx_, bounds.y_min, bounds.x_max, centery_);
	Rectangle q3(bounds.x_min, bounds.y_min, centerx_, centery_);
	Rectangle q4(bounds.x_min, centery_, centerx_, bounds.y_max);
	
	nodes[0] = (new QuadTree(level + 1, q1));
	nodes[1] = (new QuadTree(level + 1, q2));
	nodes[2] = (new QuadTree(level + 1, q3));
	nodes[3] = (new QuadTree(level + 1, q4));
}

void Utils::QuadTree::retrieve(std::vector<Rectangle*>& allobjs)
{
	for (size_t i = 0; i < objects.size(); i++)
		allobjs.push_back(objects[i]);

	if (nodes[0] != NULL) {
		nodes[0]->retrieve(allobjs);
		nodes[1]->retrieve(allobjs);
		nodes[2]->retrieve(allobjs);
		nodes[3]->retrieve(allobjs);
	}
}


int Utils::QuadTree::getIndex( Rectangle& rect)
{
	if ( rect.isInside(nodes[0]->bounds) ){
		return 0;
	}
	else if (rect.isInside(nodes[1]->bounds)) {
		return 1;
	}
	else if (rect.isInside(nodes[2]->bounds)) {
		return 2;
	}
	else if (rect.isInside(nodes[3]->bounds)) {
		return 3;
	}
	return -1;
}


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

void Utils::QuadTree::insert(Rectangle *obj)
{
	if (nodes[0] != NULL) {
		int inx = getIndex(*obj);
		if (inx != -1) {
			nodes[inx]->insert(obj);
			return;
		}
	}
	objects.push_back(obj);
	
	if (objects.size() > max_objects && nodes[0] == NULL) {
		split();
		int end = objects.size() - 1, ite = 0;
		while (ite <= end) {
			int inx = getIndex(*objects[ite]);
			if (inx != -1) {
				nodes[inx]->insert(objects[ite]);
				Rectangle * temp = objects[ite]; objects[ite] = objects[end]; objects[end] = temp;
				--end;
			}
			else
				++ite;
		}
		while (objects.size() != end + 1)
			objects.pop_back();
	}
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