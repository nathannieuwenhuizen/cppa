#pragma once
#include "Role.h";
#include <iostream>

class Shaman: public Role
{
public:
	Shaman(NPC* npc);
	~Shaman();
	void draw() const;
};

