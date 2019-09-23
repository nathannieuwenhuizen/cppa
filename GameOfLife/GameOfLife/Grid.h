#pragma once

#include <iostream>
#include <vector>

class Grid
{
public:
	
	int size;
	std::vector<int> cells = {  };
	Grid(int _size);
	int amountOfLivingNeighbours(int index);
	void draw();
	~Grid();
};

