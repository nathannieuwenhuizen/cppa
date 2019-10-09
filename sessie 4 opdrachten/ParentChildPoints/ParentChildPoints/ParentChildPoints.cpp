// ParentChildPoints.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Parent.h"

int main() {

	//Parent* p1 = new Parent("Parent1");
	std::shared_ptr<Parent> p1 = std::shared_ptr<Parent>(new Parent("Parent1"));
	std::cout << "p1:" << *p1 << std::endl;
	std::cout << "shared point use count: " << p1.use_count() << std::endl;


	std::shared_ptr<Parent> p2 = p1; // roept de copy constructor aan
	std::cout << "p2:" << *p2 << std::endl;
	std::cout << "shared point use count: " << p1.use_count() << " | " << p2.use_count() << std::endl;

	std::shared_ptr<Parent> p3 = std::shared_ptr<Parent>(new Parent("Parent3"));
	std::cout << "p3:" << *p3 << std::endl;
	p3 = p1; // roept de assignment operator aan
	std::cout << "p1:" << *p3 << std::endl;
	std::cout << "shared point use count: " << p1.use_count() << " | " << p2.use_count() << " | " << p3.use_count() << std::endl;
	
	std::cout << " child count: " << *p1 << " | " << *p2 << " | " << *p3 << std::endl;
	p3->child = nullptr;
	std::cout << " child count: " << *p1 << " | " << *p2 << " | " << *p3 << std::endl;

	//delete p1;
	//delete p2;
	//delete p3;

	return 0;
}