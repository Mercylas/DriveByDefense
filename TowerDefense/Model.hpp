#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Player.hpp"
#include "Tower.hpp"
#include "Enemy.h"
#include "ShopKeeper.hpp"
#include "PowerUps.hpp"

class Model {
public:
	Model();
	~Model();
	void update(sf::Time);
	bool checkPlayerCollision(int);
	int talking(int direc);
	int pickUpPower(int direc);
	int whoTalking;
	int enterTower(int direc);
	void addTower(int which, int xx, int yy);
	void addTower(int which);
	void addPowerUp(int which);
	void addShopKeeper(int which, int xx, int yy, int dir);
	void addEnemy(int which);
	void exitTower();
	std::map<int, std::map<int, bool>> unpassable;
	sf::VertexArray map;
	sf::RenderStates state;
	Player player;
	sf::Texture tileset;
	std::vector<Tower> towers;
	std::vector<ShopKeeper> shops;
	std::vector<Enemy> enemies;
	std::vector<PowerUps> powerUps;
	int winh, winw, gameMode, mapRows, mapCols, lives, mapX, mapY;
	std::map<int, std::map<int, bool>> checkPoint;
	float mapRotation, dispX, dispY;
};