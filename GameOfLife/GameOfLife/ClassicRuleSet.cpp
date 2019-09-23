#include "pch.h"
#include "ClassicRuleSet.h"
#include "Grid.h"

ClassicRuleSet::ClassicRuleSet(Grid _grid) : grid(_grid)
{
}

ClassicRuleSet::~ClassicRuleSet()
{
}

std::vector<int> ClassicRuleSet::applyRule() {
	std::vector<int> newGrid = grid.cells;
	for (std::vector<int>::iterator it = newGrid.begin(); it != newGrid.end(); ++it) {
		int index = it - newGrid.begin();
		int amountOfLiving = grid.amountOfLivingNeighbours(index);

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
	grid.cells = newGrid;
	return newGrid;
}