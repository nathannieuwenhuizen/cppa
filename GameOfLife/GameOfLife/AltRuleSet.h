#pragma once
#include "pch.h"
#include "Grid.h"

class AltRuleSet
{
public:
	AltRuleSet(Grid _grid);
	~AltRuleSet();


	std::vector<int> applyRule();
	Grid grid;

};

