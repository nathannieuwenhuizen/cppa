#pragma once

#include <iostream>
#include <vector>
#include "Ruleset.h"

class Grid
{
public:
	
	int size;
	std::vector<int> cells = {  };
	
	Grid(int _size, Ruleset* ruleset);
	void iteration();
	Ruleset* ruleset;
	void draw();
	~Grid();
};

