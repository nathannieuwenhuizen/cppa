#include "pch.h"
#include "Grid.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Grid::Grid(int _size) : size(_size)
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
		

		//std::cout << ' ' << *it << " hallo " << index % size <<  std::endl;
	}
}

int Grid::amountOfLivingNeighbours(int index) {

	std::vector<int> neighbours = {};
	int result = 0;
	//isn't on top row
	if (index > size) {
		neighbours.push_back(cells[index - size]); //top
		if (index % size > 1) {
			neighbours.push_back(cells[index - (size - 1)]); //top left
		}

		if (index % size < size - 1) {
			neighbours.push_back(cells[index - (size + 1)]); //top right
		}

	}

	//isnt on bottom row
	if (index < (size * size) - size -1) {
		neighbours.push_back(cells[index + size]); //bottom
		if (index % size > 1) {
			neighbours.push_back(cells[index + (size - 1)]); //bottom left
		}

		if (index % size < size - 1) {
			neighbours.push_back(cells[index + (size + 1)]); //bottom right
		}

	}
	if (index % size > 1) {
		neighbours.push_back(cells[index - 1]); //left
	}

	if (index % size < size - 1) {
		neighbours.push_back(cells[index + 1]); //right
	}


	for (std::vector<int>::iterator it = neighbours.begin(); it != neighbours.end(); ++it) {
		if (*it == 1) {
			result++;
		}
		//std::cout << ' ' << *it << " hallo " << index % size <<  std::endl;
	}

	return result;
}


Grid::~Grid()
{
}
