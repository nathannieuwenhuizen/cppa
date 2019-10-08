#pragma once
#include <vector>
class Ruleset
{
public:
	virtual ~Ruleset();
	Ruleset();
	virtual std::vector<int> applyRule(std::vector<int> grid, int size) = 0;
	int amountOfLivingNeighbours(std::vector<int> cells, int size, int index);

};

