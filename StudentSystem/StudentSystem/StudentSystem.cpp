// StudentSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Docent.h"
#include <vector>
#include "Module.h"
#include "Student.h"

#include <string> 
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

void putTeachersAndStudentsIntoModules();
void showModuleList();
void showStudentECs();

std::vector<Module*> modules = {};
std::vector<Docent*> docenten = {};
std::vector<Student*> studenten = {};
int main()
{
	//declaration
	modules.push_back(new Module("OBOPA", 2));
	modules.push_back(new Module("Kernmodule 1", 5));
	modules.push_back(new Module("Afval opruimen", 8));

	docenten.push_back(new Docent("Edwin"));
	docenten.push_back(new Docent("Johan"));
	docenten.push_back(new Docent("Corne"));
	std::cout << modules[0]->naam;
	for (int i = 0; i < 10; i++) {
		studenten.push_back(new Student("Student #" + std::to_string(i)));
		//std::cout << "hello" << i << std::endl;
	}

	putTeachersAndStudentsIntoModules();
	showModuleList();
	showStudentECs();
	modules[0]->ec = 180;
	std::cout << "OBOPA EC changed to 180, can I has diploma now?" << std::endl;
	showStudentECs();
	modules[0]->studenten.pop_back();
	std::cout << "Student removed from first module" << std::endl;

	showModuleList();

}

void putTeachersAndStudentsIntoModules() {
	for (int j = 0; j < modules.size(); ++j) {
		modules[j]->docent = *docenten[j];
		//std::cout << "docent added" << docenten[j]->naam;
	}
	srand(time(NULL));
	for (int i = 0; i < studenten.size(); ++i) {
		int randomModule = i % 3;
		modules[randomModule]->studenten.push_back(studenten[i]);
		(*studenten[i]).modules.push_back(modules[randomModule]);
		
		randomModule = (i+ 1) % 3;
		modules[randomModule]->studenten.push_back(studenten[i]);
		(*studenten[i]).modules.push_back(modules[randomModule]);
	}


}
void showStudentECs() {
	std::cout << "students EC: " << std::endl;

	for (int i = 0; i < studenten.size(); ++i) {
		std::cout << studenten[i]->naam << " total EC: " << studenten[i]->totalEC() << std::endl;
	}

}

void showModuleList() {
	std::vector<Module*>::iterator it = modules.begin();
	while (it != modules.end()) {
		(*it)->getInfo();
		it++;
	}
}