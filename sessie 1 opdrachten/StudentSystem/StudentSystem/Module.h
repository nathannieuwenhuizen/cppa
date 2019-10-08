#pragma once
#include <iostream>
#include "Docent.h"
#include "Student.h"
#include <vector>
class Module
{
public:
	std::string naam;
	int ec;
	Docent docent;
	std::vector<Student*> studenten;

	Module(std::string naam, int ec);
	~Module();
	void getInfo();
};

