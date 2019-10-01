#pragma once
#include "NPC.h";
#include <iostream>

class Elf : public NPC
{
public:
	Elf();
	~Elf();
	void draw() const;

};