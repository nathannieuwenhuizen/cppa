#pragma once
#include "pch.h"
#include "RuleSet.h"

class ClassicRuleSet : public Ruleset
{
public:
	ClassicRuleSet();
	~ClassicRuleSet();
	std::vector<int> applyRule(std::vector<int> grid, int size) override;

};

