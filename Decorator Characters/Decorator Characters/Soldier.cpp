#include "pch.h"
#include "Soldier.h"


Soldier::Soldier(NPC* npc) : Role(npc)
{
}


Soldier::~Soldier()
{
}
void Soldier::draw() const {
	Role::render();
	std::cout << "Soldier, lets get down to buisness, to defeat the huns!" << std::endl;
}

