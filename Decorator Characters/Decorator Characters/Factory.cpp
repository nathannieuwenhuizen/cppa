#include "pch.h"
#include "Factory.h"

#include "Orc.h"
#include "Elf.h"

#include "Farmer.h"
#include "Soldier.h"
#include "Shaman.h"

Factory::Factory()
{
}


Factory::~Factory()
{
}

NPC* Factory::createNPC(Race race, Roles roles) {
	NPC* npc = nullptr;

	switch (race)
	{
	case ElfRace:
		npc = new Elf();
		break;
	case OrcRace:
		npc = new Orc();
		break;
	default:
		break;
	}

	switch (roles)
	{
	case FarmerRole:
		npc = new Farmer(npc);
		break;
	case SoldierRole:
		npc = new Soldier(npc);
		break;
	case ShamanRole:
		npc = new Shaman(npc);
		break;
	default:
		break;
	}

	return npc;
}