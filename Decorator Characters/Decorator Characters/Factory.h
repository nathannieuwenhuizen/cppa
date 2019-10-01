#pragma once
#include "NPC.h";
#include <iostream>

enum Race {
	ElfRace,
	OrcRace
};

enum Roles {
	None,
	FarmerRole,
	SoldierRole,
	ShamanRole
};

class Factory
{
public:
	Factory();
	~Factory();
	NPC* createNPC(Race race, Roles roles = Roles::None);
};

