#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Inventory.h"
class Enemy : public sf::Drawable, public sf::Transformable
{
public:
	Enemy(int);
	~Enemy();
	int sequenceIndex;
	int state; //standing=1, walking down=2, walking left =3, walking right=4, walking up=5
	void update(sf::Time delta);
	void setTexCord();
	void addFrame(sf::IntRect rect);
	bool isDead();
	void UpdatePos(int mapX, int mapY);
	Inventory inventory;
private:
	float frameTime;
	float frameRate;
	int type, checkpoint, health, posX, posY;
	std::vector<sf::IntRect> playerFrames;
	sf::Texture texSheet;
	sf::VertexArray vertices;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};