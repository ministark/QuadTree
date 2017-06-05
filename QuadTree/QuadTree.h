#include <vector>
#include <iostream>

#include "Rectangle.h"
#pragma once

namespace Utils {
	class QuadTree
	{
	private:
		std::vector<Rectangle*> objects;
		int max_objects = 10;
		int max_levels = 10;
		int level;
		Utils::Rectangle bounds;
		QuadTree* nodes[4];
	public:
		QuadTree();
		QuadTree(int lvl, Utils::Rectangle pbounds);
		void clear();
		void setMaxObjects(int obj);
		void setMaxLevels(int lvl);
		~QuadTree();
	};


}

