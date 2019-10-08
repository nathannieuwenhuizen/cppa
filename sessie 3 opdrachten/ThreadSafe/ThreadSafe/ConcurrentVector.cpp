#include "pch.h"
#include "ConcurrentVector.h"
#include <iostream>
#include <Windows.h>


ConcurrentVector::ConcurrentVector(std::vector<int> _vector)
{
	vector = new std::vector<int>{};
	mutex = new std::mutex();
}

ConcurrentVector::~ConcurrentVector()
{
}

int ConcurrentVector::add(int val)
{
	Sleep(1000);

	mutex->lock();
	vector->push_back(val);
	std::cout << "adding = " << val << " and size = " << vector->size() << std::endl;

	mutex->unlock();
	return val;
}

std::ostream& operator<<(std::ostream & os, const ConcurrentVector & cv)
{
	os << "vector: ";
	for (auto i = 0; i < cv.vector->size(); i++) {
		os << (*cv.vector)[i] << ", ";
	}
	os << std::endl;
	return os;
}
