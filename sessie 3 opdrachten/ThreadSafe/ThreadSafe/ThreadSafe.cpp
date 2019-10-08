// ThreadSafe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <thread>
#include "ConcurrentVector.h"

ConcurrentVector concurentVector = ConcurrentVector(std::vector<int>{1, 2, 3});
std::mutex mutex;

void calculate() {

	std::vector<std::thread> threads;
	for (int i = 1; i <= 10; i++) {
		//concurentVector.add(i);
		threads.push_back(std::thread(&ConcurrentVector::add, concurentVector, i * 10));
	}

	for (auto& thread : threads) {
		
		thread.join();
	}
	std::cout << "total = " << concurentVector << std::endl;
}

int main() {
	//concurentVector = ConcurrentVector(std::vector<int>{});
	for (int i = 0; i < 10; ++i) {
		calculate();
		concurentVector.vector->clear();
	}

	return 0;
}