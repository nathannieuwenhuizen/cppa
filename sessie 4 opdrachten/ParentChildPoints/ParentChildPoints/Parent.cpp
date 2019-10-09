#include "pch.h"
#include <iostream>
#include "Parent.h"

Parent::Parent(std::string name) {
	this->name = name;
	std::string childName = "ChildOf" + name;
	this->child = std::unique_ptr<Child>(new Child(childName));
	//this->child = new Child(childName);
}

Parent::Parent(const Parent& other) {
	std::cout << "Parent cctor" << std::endl;
	this->name = other.name;
	this->child = std::unique_ptr<Child>(new Child(std::move(*other.child)));
	//this->child = new Child(*other.child);
}

Parent::~Parent() {
	std::cout << "Parent dtor : " << this->name << std::endl;
	//delete this->child;
}

Parent& Parent::operator=(const Parent& other) {
	std::cout << "Parent assignment" << std::endl;

	if (this == &other) return *this;

	this->name = other.name;
	//delete this->child;
	//this->child = new Child(*other.child);
	this->child = std::unique_ptr<Child>(new Child(std::move(*other.child)));

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Parent& parent) {
	os << "parent name: " << parent.name;
	if (parent.child) {
		os << ", " << *parent.child;
	}
	else {
		os << ",  no child";
	}
	return os;
}
