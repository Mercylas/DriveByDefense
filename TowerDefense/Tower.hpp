#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

class Tower : public sf::Drawable, public sf::Transformable
{

public:
	Tower();
	Tower(int which, int xx, int yy);
	~Tower();
	void moveTower(int xx, int yy);
	sf::Vector2f positionTower();
	int sequenceIndex;
	int state; //standing=1, walking down=2, walking left =3, walking right=4, walking up=5
	bool moving;
	int type;
	void setTowerText(sf::Texture* towerTextSheet);

private:
	sf::Texture* texSheet;
	sf::VertexArray vertices;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};