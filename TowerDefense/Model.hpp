#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Player.hpp"
#include "Tower.hpp"
#include "Enemy.h"
class Model {
public:
	Model();
	~Model();
	void update(sf::Time);
	bool checkPlayerCollision(int);
	int enterTower(int direc);
	void addTower(int which, int xx, int yy);
	void addEnemy(int which);
	void exitTower();
	std::map<int, std::map<int, bool>> unpassable;
	sf::VertexArray map;
	sf::RenderStates state;
	Player player;
	sf::Texture tileset;
	std::vector<Tower> towers;
	std::vector<Enemy> enemies;
	int winh, winw, gameMode, mapRows, mapCols, lives, mapX, mapY;
	std::map<int, std::map<int, bool>> checkPoint;
	float mapRotation, dispX, dispY;
};