#pragma once
#include <vector>
#include <mutex>
#include <ostream>

class ConcurrentVector
{
public:

	std::vector<int>* vector;
	ConcurrentVector(std::vector<int> vector);
	~ConcurrentVector();
	int add(int val);
	std::mutex * mutex;
	friend std::ostream& operator<<(std::ostream& os, const ConcurrentVector& cv);
};

