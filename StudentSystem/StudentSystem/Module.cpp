#include "pch.h"
#include "Module.h"
#include <string>
#include <iostream>
Module::Module(std::string naam, int ec) : naam(naam) , ec(ec)
{
}


Module::~Module()
{
}

void Module::getInfo() {
	std::cout << "Module: " << naam << std::endl;
	std::cout << "EC: " << ec << std::endl << std::endl;
	std::cout << "Docent:" << std::endl;
	std::cout << "" << docent.naam << std::endl << std::endl;
	std::cout << "Studenten aantal: " << studenten.size() << std::endl;
	for (int i = 0; i < studenten.size(); ++i) {
		std::cout << studenten[i]->naam << std::endl;
	}
	std::cout << "----------------------- " << std::endl << std::endl;
}
