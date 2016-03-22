#include "Inventory.h"



Inventory::Inventory()
{
	int a = 1000;
	this->murse.push_back(a);
	this->gold = &this->murse.at(0);
}


Inventory::~Inventory()
{
}

std::string Inventory::returnGoldAmount()
{
	std::string goldStr = "Gold: " + this->murse.at(0);
	std::cout << this->murse.at(0) << std::endl;

	return goldStr;
}
