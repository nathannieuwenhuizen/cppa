#pragma once
#include "pch.h"
#include "RuleSet.h"


class RuleSet2 : public Ruleset
{
public:
	RuleSet2();
	~RuleSet2();
	std::vector<int> applyRule(std::vector<int> grid, int size) override;

};

