#include "pch.h"
#include "AltRuleSet2.h"
#include "Grid.h"


AltRuleSet2::AltRuleSet2(Grid _grid) : grid(_grid)
{
}

AltRuleSet2::~AltRuleSet2()
{
}

std::vector<int> AltRuleSet2::applyRule() {
	std::vector<int> newGrid = grid.cells;
	for (std::vector<int>::iterator it = newGrid.begin(); it != newGrid.end(); ++it) {
		int index = it - newGrid.begin();
		int amountOfLiving = grid.amountOfLivingNeighbours(index);

		if (*it == 0) {
			if (amountOfLiving == 4) {
				newGrid[index] = 1;
			}
		}
		else {
			if (amountOfLiving >= 2 && amountOfLiving <= 4) {
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