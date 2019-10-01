#pragma once
#include <ctime>
#include <istream>
class Transactie
{
public:
	Transactie(bool _added, int _amount, std::string _date);
	~Transactie();
	bool added;
	int amount;
	std::string date;
};

