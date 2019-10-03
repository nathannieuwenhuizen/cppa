#include "pch.h"
#include "Grid.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Grid::Grid(int _size, Ruleset* ruleset) : size(_size), ruleset(ruleset)
{
	srand(time(NULL));

	for (int i = 0; i != size * size; ++i) {
		if (rand() % 100 > 50) {
			cells.push_back(1);
		}
		else {
			cells.push_back(0);
		}
		/*if ((i % 2) == 0) {
			cells.push_back(1);
		}
		else {
			cells.push_back(0);
		}*/

	} 
}

void Grid::draw() {
	for (std::vector<int>::iterator it = cells.begin(); it != cells.end(); ++it) {
		int index = it - cells.begin();
		if (index % size == 0) {
			std::cout << std::endl;
		}

		
		if (*it == 0) {
			std::cout << "  ";
		}
		else {
			std::cout << "*";
		}
	}
}

Grid::~Grid()
{
}
void Grid::iteration() {
	cells = ruleset->applyRule(cells, size);
}