#pragma once
#include "pch.h"
#include "Grid.h"

class SecondAltRule
{
public:
	SecondAltRule(Grid _grid);
	~SecondAltRule();
	std::vector<int> applyRule();
	Grid grid;

};

