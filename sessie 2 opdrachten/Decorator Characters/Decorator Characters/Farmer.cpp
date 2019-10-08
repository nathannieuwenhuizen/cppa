#include "pch.h"
#include "Farmer.h"

Farmer::Farmer(NPC* npc) : Role(npc)
{
}


Farmer::~Farmer()
{
}
void Farmer::draw() const {
	Role::render();
	std::cout << "Farmer, it aint much but its honest work." << std::endl;
}
