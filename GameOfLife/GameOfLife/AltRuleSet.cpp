#include "pch.h"
#include "AltRuleSet.h"
#include "Grid.h"


AltRuleSet::AltRuleSet(Grid _grid) : grid(_grid)
{
}


AltRuleSet::~AltRuleSet()
{
}
std::vector<int> AltRuleSet::applyRule() {
	std::vector<int> newGrid = grid.cells;
	for (std::vector<int>::iterator it = newGrid.begin(); it != newGrid.end(); ++it) {
		int index = it - newGrid.begin();
		int amountOfLiving = grid.amountOfLivingNeighbours(index);

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
	grid.cells = newGrid;
	return newGrid;
}