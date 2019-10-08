#include "pch.h"
#include "Student.h"
#include "Module.h"

Student::Student(std::string naam) : naam(naam)
{
}


Student::~Student()
{
}

int Student::totalEC() {
	int result = 0;
	for (int i = 0; i < modules.size(); ++i) {
		result += (modules[i])->ec;
	}
	return result;
}
