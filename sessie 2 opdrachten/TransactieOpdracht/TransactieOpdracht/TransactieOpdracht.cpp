// TransactieOpdracht.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "BankRekening.h";
#include "Transactie.h";
#include <ctime>
#include <vector>
#include <chrono>

void MakeTransaction(BankRekening* from, BankRekening* to, int amount);
std::string NowToString();

int main()
{
	BankRekening* rekeningA = &BankRekening(100, std::vector<Transactie>{});
	BankRekening* rekeningB = &BankRekening(100, std::vector<Transactie>{});
	std::cout << *rekeningA << std::endl;
	std::cout << *rekeningB << std::endl;

	MakeTransaction(rekeningA, rekeningB, 20);
	MakeTransaction(rekeningB, rekeningA, 55);
	std::cout << *rekeningA << std::endl;
	std::cout << *rekeningB << std::endl;

	return 0;
}

void MakeTransaction(BankRekening* from, BankRekening* to, int amount) {
	
	*from += Transactie(false, amount, NowToString());
	*to += Transactie(true, amount, NowToString());
}
std::string NowToString()
{
	std::chrono::system_clock::time_point p = std::chrono::system_clock::now();
	time_t t = std::chrono::system_clock::to_time_t(p);
	char str[26];
	ctime_s(str, sizeof str, &t);
	return str;
}