#pragma once
#include "Role.h";
#include <iostream>

class Farmer : public Role
{

public:
	Farmer(NPC* npc);
	~Farmer();
	void draw() const;
};

