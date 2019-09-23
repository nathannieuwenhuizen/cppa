#pragma once
#include "pch.h"
#include "Grid.h"

class ClassicRuleSet
{
public:
	ClassicRuleSet(Grid _grid);
	~ClassicRuleSet();
	std::vector<int> applyRule();
	Grid grid;
};

