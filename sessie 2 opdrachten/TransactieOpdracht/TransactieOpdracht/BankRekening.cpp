#include "pch.h"
#include "BankRekening.h"

BankRekening::BankRekening(int _amount, std::vector<Transactie> _history)
{
	history = _history;
	amount = _amount;
}


BankRekening::~BankRekening()
{
}

BankRekening BankRekening::operator+(const Transactie& t) {
	amount += (t.amount * (t.added == true ? -1 : 1));
	history.push_back(t);
	return BankRekening(amount, history);
}
BankRekening BankRekening::operator-(const Transactie& t) {
	amount -= (t.amount * (t.added == true ? -1 : 1));
	return BankRekening(amount, history);
}

BankRekening& BankRekening::operator+=(const Transactie& t) {
	amount += (t.amount * (t.added == true ? -1 : 1));
	history.push_back(t);
	return *this;
}
BankRekening& BankRekening::operator-=(const Transactie& t) {
	amount -= (t.amount * (t.added == true ? -1 : 1));
	return *this;
}

std::ostream & operator<<(std::ostream& os, const BankRekening & b)
{
	os << "------------" << std::endl << "bank amount: " << b.amount << std::endl << "history transactions: " << std::endl;
	for (int i = 0; i < b.history.size(); ++i) {
		std::string message = " added at ";
		if (b.history[i].added == false) {
			message = " removed at ";
		}
		os << "transaction: " << b.history[i].amount << message << b.history[i].date;
	}
	os << "------------" << std::endl;
	return os;
}
