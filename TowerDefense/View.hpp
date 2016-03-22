#pragma once
#include "Model.hpp"
#include "ShopBox.hpp"

class View {
public:
	View(Model* m);
	~View();
	bool talking;
	void render();
	void loadPlayerText();
	void loadTowerText();
	void loadShopKeepText();
	void setNewTowerTexture();
	void setText(int who);
	sf::Text sell;
	sf::Text gold;
	sf::Font fonterino;
	Model* model;
	ShopBox dialogueBox;
	sf::RenderWindow window;
	sf::Texture playerText;
	sf::Texture towersText;
	sf::Texture shopKeeperText;
};