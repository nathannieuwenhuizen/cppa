#include "pch.h"
#include "RuleSet2.h"

RuleSet2::RuleSet2()
{
}


RuleSet2::~RuleSet2()
{
}
std::vector<int> RuleSet2::applyRule(std::vector<int>  grid, int size) {
	std::vector<int> newGrid = grid;
	for (std::vector<int>::iterator it = newGrid.begin(); it != newGrid.end(); ++it) {
		int index = it - newGrid.begin();
		int amountOfLiving = Ruleset::amountOfLivingNeighbours(grid, size, index);

		if (*it == 0) {
			if (amountOfLiving == 2) {
				newGrid[index] = 1;
			}
		}
		else {
			if (amountOfLiving >= 1 && amountOfLiving <= 2) {
				newGrid[index] = 1;
			}
			else {
				newGrid[index] = 0;
			}

		}

	}
	return newGrid;
}