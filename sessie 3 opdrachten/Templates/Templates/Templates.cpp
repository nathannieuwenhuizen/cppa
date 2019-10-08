// Templates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <array>
#include <string>
#include "MyTemplateQueue.h"
#include "myPair.h"


template<class T>
void Sort(T* arr)
{
	std::cout << "sorting... " << std::endl;

	if (typeid((*arr)[0]).name() == typeid(float).name()) {
		int n = sizeof((*arr)) / sizeof((*arr)[0]);
		float i, j, min; 
		auto temp = (*arr)[0];
		for (i = 0; i < n - 1; i++) {
			min = i;
			for (j = i + 1; j < n; j++)
				if ((*arr)[j] < (*arr)[min])
					min = j;
			temp = (*arr)[i];
			(*arr)[i] = (*arr)[min];
			(*arr)[min] = temp;
		}
	}
	else {
		std::sort(arr->begin(), arr->end());
	}
}

template<class T>
void coutArray(T arr) {
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		std::cout << arr[i] << ", ";
	}
	std::cout << std::endl;
}

int main()
{

	std::array<float, 7> arrayInt = { 1, 67.1, 67,4,7, 55, 23456 };
	coutArray(arrayInt);
	Sort((&arrayInt));
	coutArray(arrayInt);

	std::array<std::string, 6> arrayString = {"dit script", "zzz...", "hallo", "poep", "banaan", "whaaa" };
	coutArray(arrayString);
	Sort((&arrayString));
	coutArray(arrayString);

	MyTemplateQueue<int> myQueue(new int[3] {1, 2, 3});
	std::cout << myQueue;
	myQueue.put(5);
	std::cout << myQueue;
	int val = myQueue.get();
	std::cout << myQueue;
	std::cout << val;

	MyTemplateQueue<char> myCharQueue(new char[3]{ 'a', 't', 'm' });
	std::cout << myCharQueue;
	myCharQueue.put('b');
	std::cout << myCharQueue;
	char charval = myCharQueue.get();
	std::cout << myCharQueue;
	std::cout << charval;


}