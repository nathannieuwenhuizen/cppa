#include "pch.h"
#include "Role.h"

Role::Role(NPC* npc) : npc(npc)
{
}


Role::~Role()
{
}

void Role::render() const {
	npc->draw();
	std::cout << "My role is ";

}