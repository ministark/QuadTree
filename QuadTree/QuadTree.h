#include <vector>
#include <iostream>

#include "Rectangle.h"
#pragma once

namespace Utils {
	class QuadTree
	{
	private:
		// Variables
		std::vector<Rectangle*> objects;
		int max_objects = 10;
		int max_levels = 10;
		int level;
		QuadTree* nodes[4];
		// Function
		void split();
		void retrieve(std::vector<Rectangle*> &);
		int  getIndex(Rectangle&);
	public:
		Utils::Rectangle bounds;
		QuadTree();
		QuadTree(int lvl, Utils::Rectangle pbounds);
		void clear();
		void insert(Rectangle *);
		void setMaxObjects(int obj);
		void setMaxLevels(int lvl);
		~QuadTree();
	};


}

