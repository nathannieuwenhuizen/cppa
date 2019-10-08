#include "pch.h"
#include "Ruleset.h"


Ruleset::Ruleset()
{
}

Ruleset::~Ruleset()
{
}


int Ruleset::amountOfLivingNeighbours(std::vector<int> cells, int size, int index) {
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
	if (index < (size * size) - size - 1) {
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
