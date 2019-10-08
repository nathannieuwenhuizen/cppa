#pragma once
#include "Role.h";
#include <iostream>

class Soldier : public Role
{
public:
	Soldier(NPC* npc);
	~Soldier();
	void draw() const;
};

