#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Inventory
{
public:
	Inventory();
	~Inventory();
	int* gold;
	std::vector<int> murse;
	std::string returnGoldAmount();
};

