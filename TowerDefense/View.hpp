#pragma once
#include "Model.hpp"

class View {
public:
	View(Model* m);
	~View();
	void render();
	Model* model;
	sf::RenderWindow window;
};