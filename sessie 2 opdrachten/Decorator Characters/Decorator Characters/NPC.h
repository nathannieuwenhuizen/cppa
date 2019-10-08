#pragma once
class NPC
{
public:
	NPC();
	virtual ~NPC();
	virtual void draw() const = 0;
};

