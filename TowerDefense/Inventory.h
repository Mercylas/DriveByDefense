#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string> 

class Inventory
{
public:
	Inventory();
	~Inventory();
	int* gold;
	bool canAfford(int price);
	std::vector<int> murse;
	std::string returnGoldAmount();
};

