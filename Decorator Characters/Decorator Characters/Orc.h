#pragma once
#include "NPC.h";
#include <iostream>

class Orc : public NPC
{
public:
	Orc();
	~Orc();
	void draw() const;
};