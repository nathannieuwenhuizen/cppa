#include "pch.h"
#include "Shaman.h"

Shaman::Shaman(NPC* npc) : Role(npc)
{
}


Shaman::~Shaman()
{
}
void Shaman::draw() const {
	Role::render();
	std::cout << " Shaman, magic is kanda my thing!" << std::endl;
}
