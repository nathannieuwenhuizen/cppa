#pragma once
#include <iostream>
#include <vector>

class Module;

class Student
{
public:

	Student(std::string naam);
	~Student();

	std::string naam = "naam student";
	std::vector<Module*> modules;

	int totalEC();
};

