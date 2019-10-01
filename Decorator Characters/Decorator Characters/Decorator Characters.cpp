//---------------------------------------------------------------
//
//with the hulp of Edwin and Casey.
//https://github.com/Casey-Hofland/EdwinsOpdrachten/tree/master/NPCFactory
//https://github.com/edovino/OBOPA/tree/master/Sessie%202/Voorbeeld_DecoratorFactoryMethod
//
//---------------------------------------------------------------

#include "pch.h"
#include <iostream>
#include <vector>

#include "Factory.h";
#include "NPC.h";

void draw();

Factory factory;
std::vector<NPC*> npcs;
int main()
{
	npcs = std::vector<NPC*>{};
	factory = Factory();

	npcs.push_back(factory.createNPC(Race::OrcRace, Roles::SoldierRole));
	npcs.push_back(factory.createNPC(Race::ElfRace, Roles::FarmerRole));
	draw();
}

void draw() {
	for (auto& npc : npcs)
	{
		npc->draw();
		std::cout << std::endl;
	}
}