#include "pch.h"
#include "SecondAltRule.h"
#include "Grid.h"

SecondAltRule::SecondAltRule(Grid _grid) : grid(_grid)
{
}


SecondAltRule::~SecondAltRule()
{
}
std::vector<int> SecondAltRule::applyRule() {
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