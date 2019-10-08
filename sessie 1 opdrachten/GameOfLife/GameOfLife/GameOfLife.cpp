// GameOfLife.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <windows.h>

#include "Grid.h"
#include "ClassicRuleSet.h"
#include "Ruleset.h"
#include "RuleSet2.h"
#include "RuleSet3.h"

int main()
{
	//Ruleset* ruleSet = new ClassicRuleSet();
	//Ruleset* ruleSet = new RuleSet2();
	Ruleset* ruleSet = new RuleSet3();

	Grid grid(25, ruleSet);

	grid.draw();
	Sleep(10);

	while (true) {
		if (system("CLS")) system("clear");
		grid.iteration();
		grid.draw();
		Sleep(10);
	}

}