#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

class ShopKeeper : public sf::Drawable, public sf::Transformable
{

public:
	ShopKeeper();
	ShopKeeper(int which, int xx, int yy, int dir);
	~ShopKeeper();
	void setTextSheet(sf::Texture *textSheet);
	void movePlayer(int xx, int yy);
	sf::Vector2f positionPlayer();
	std::string shopMenu;
	int direction;

private:
	std::vector<sf::IntRect> playerFrames;
	sf::Texture* texSheet;
	sf::VertexArray vertices;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};