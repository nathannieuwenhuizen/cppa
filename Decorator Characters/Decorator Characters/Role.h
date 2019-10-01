#pragma once
#include "NPC.h";
#include <iostream>

class Role : public NPC
{
public:
	Role(NPC* npc);
	~Role();
	void render() const;
private:
	NPC* npc;
};

