#pragma once

#include "RuleSet.h"

class RuleSet3 : public Ruleset
{
public:
	RuleSet3();
	~RuleSet3();
	std::vector<int> applyRule(std::vector<int> grid, int size) override;

};

