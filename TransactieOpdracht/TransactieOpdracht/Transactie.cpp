#include "pch.h"
#include "Transactie.h"


Transactie::Transactie(bool _added, int _amount, std::string _date) : added(_added) , amount(_amount) , date(_date)
{
}


Transactie::~Transactie()
{
}
