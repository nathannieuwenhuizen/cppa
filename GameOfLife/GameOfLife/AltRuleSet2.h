#pragma once
#include "pch.h"
#include "Grid.h"

class AltRuleSet2
{
public:
	AltRuleSet2(Grid _grid);
	~AltRuleSet2();
	std::vector<int> applyRule();
	Grid grid;
};

