#pragma once
#include "Transactie.h"
#include <ostream>
#include <vector>
#include <string>

class BankRekening
{
public:

	BankRekening(int _amount, std::vector<Transactie> _history);
	~BankRekening();
	BankRekening operator+(const Transactie& t);
	BankRekening& operator+=(const Transactie& t);
	BankRekening operator-(const Transactie& t);
	BankRekening& operator-=(const Transactie& t);

	friend std::ostream& operator<<(std::ostream& os, const BankRekening& b);
	int amount; 
	std::vector<Transactie> history;

private:
};

