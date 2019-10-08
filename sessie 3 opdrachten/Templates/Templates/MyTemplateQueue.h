#pragma once
#include <iostream>

template<class T>
class MyTemplateQueue
{
public:
	T *list;
	int size;
	MyTemplateQueue(T init[])
	{
		list = init; 
		size = sizeof(init) - 1;
		//list[0] = init;
	}

	void put(T val) {
		// Create the new array - user must be told to delete it at some point
		T* newList = new T[size + 1];
		
		
		for (int i = 0; i <= size + 1; ++i)
		{
			if (i == size)  // All the elements before the one that must be inserted
			{
				newList[i] = val;
			} else 
			{
				newList[i] = list[i];
			}
		}
		size++;
		std::cout << "putting " << val << " into queue" << std::endl;
		list = newList;
	}

	friend std::ostream& operator<<(std::ostream& os, const MyTemplateQueue<T>& b) {
		os << "my aqesome queue: (";
		for (int i = 0; i < b.size; ++i) {
			os <<b.list[i];
			if (i != b.size - 1) {
				os << ", ";
			}
		}
		os << ") " << std::endl;
		return os;
	}
	T get()
	{
		T result = list[0];
		for (int i = 0; i < size; ++i) {
			list[i] = list[i + 1]; // copy next element left
		}
		size--;
		std::cout << "getting " << result << " from queue" << std::endl;

		return result;
	}
	//	~MyTemplateQueue();
	/*T get();
	*/

};

