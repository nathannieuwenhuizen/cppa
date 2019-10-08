#include "pch.h"
#include "ClassicRuleSet.h"

ClassicRuleSet::ClassicRuleSet()
{
}

ClassicRuleSet::~ClassicRuleSet()
{
}

std::vector<int> ClassicRuleSet::applyRule(std::vector<int>  grid, int size) {
	std::vector<int> newGrid = grid;
	for (std::vector<int>::iterator it = newGrid.begin(); it != newGrid.end(); ++it) {
		int index = it - newGrid.begin();
		int amountOfLiving = Ruleset::amountOfLivingNeighbours(grid, size, index);

		if (*it == 0) {
			if (amountOfLiving == 3) {
				newGrid[index] = 1;
			}
		}
		else {
			if (amountOfLiving >= 2 && amountOfLiving <= 3) {
				newGrid[index] = 1;
			}
			else {
				newGrid[index] = 0;
			}

		}
		
	}
	return newGrid;
}