#include "Model.hpp"

Model::Model() {
	winh = 960;
	winw = 1280;
	mapX = 0;
	mapY = 0;
	mapRotation = 0;
	const int level[] =
	{
		36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
		36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
		36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
		36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
		36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
		36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
		36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
		36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 34, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 35, 67, 51, 51, 51, 51, 51, 58, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
		36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 34, 33, 33, 33, 33, 33, 33, 33, 00, 31, 31, 77, 31, 31, 31, 31, 31, 20, 40, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
		36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 34, 33, 00, 31, 31, 20, 33, 33, 06, 72, 66, 38, 33, 33, 33, 33, 33, 06, 40, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
		36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 34, 33, 06, 33, 33, 06, 33, 33, 06, 47, 36, 73, 33, 33, 33, 33, 33, 06, 40, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
		36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 34, 33, 06, 33, 33, 06, 33, 33, 06, 47, 36, 55, 73, 33, 00, 31, 31, 07, 40, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
		36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 34, 33, 06, 33, 33, 06, 33, 33, 06, 47, 36, 36, 39, 33, 06, 48, 50, 50, 61, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
		36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 06, 33, 33, 06, 33, 33, 06, 47, 36, 36, 39, 33, 06, 67, 51, 51, 51, 36, 36, 36, 36, 36, 36, 36, 36, 36, 00,
		36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 05, 31, 07, 33, 33, 06, 33, 33, 06, 45, 42, 42, 46, 33, 15, 31, 31, 31, 31, 76, 76, 76, 76, 76, 76, 76, 76, 76, 22,
		36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 06, 33, 33, 15, 31, 31, 20, 33, 33, 33, 33, 33, 33, 33, 36, 36, 36, 36, 36, 36, 36, 36, 36, 15,
		36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 34, 33, 33, 33, 33, 06, 33, 33, 33, 33, 33, 06, 33, 33, 33, 33, 33, 33, 33, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
		36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 34, 33, 33, 00, 31, 07, 33, 33, 33, 33, 33, 06, 33, 33, 33, 33, 33, 33, 33, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
		36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 34, 33, 33, 06, 33, 33, 33, 33, 33, 33, 33, 06, 33, 33, 33, 33, 33, 33, 33, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
		36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 34, 33, 33, 06, 33, 33, 33, 33, 33, 33, 33, 06, 33, 33, 33, 33, 33, 33, 33, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
		36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 34, 33, 33, 15, 31, 31, 31, 31, 31, 31, 31, 07, 33, 33, 33, 33, 33, 33, 33, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
		36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 34, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
		36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
		36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
		36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
		36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
		36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
		36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
		36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
	};

	mapCols = 60;
	mapRows = 29;
	map.setPrimitiveType(sf::Quads);
	map.resize(mapRows*mapCols * 4);
	sf::Vector2u tileSize = sf::Vector2u(64, 64);
	tileset.loadFromFile("Assets/spritesheet.png");
	for (int i = 0; i < mapCols; ++i)
		for (int j = 0; j < mapRows; ++j)
		{
			int tileNumber = level[i + j*mapCols];
			int tmpX = (i - 10)*tileSize.x*(-1);
			int tmpY = (j - 7)*tileSize.x*(-1);
			//first checkpoint
			if (tileNumber == 22) {
				checkPoint[tmpX+64][tmpY] = true;
				//std::cout << tmpX << ", " << tmpY << ": " << checkPoint[tmpX][tmpY] << std::endl;
			}
			//checkpoints based on tiles
			if (tileNumber == 15|| tileNumber == 0 || tileNumber == 7 || tileNumber == 20 || tileNumber == 5) {
				checkPoint[tmpX][tmpY] = true;
				//std::cout << tmpX << ", " << tmpY << ": " << checkPoint[tmpX][tmpY] << std::endl;
			}
			if (tileNumber != 33) {
				tmpX -= 32;
				unpassable[tmpX][tmpY] = true;
				//std::cout << tmpX << ", "<< tmpY<< ": "<<unpassable[tmpX][tmpY]<<std::endl;
			}
			else {
				unpassable[((i - 10)*(-1)*tileSize.x) - 32][(j - 7)*tileSize.y*(-1)] = false;
			}
			int tu = tileNumber % (tileset.getSize().x / tileSize.x);
			int tv = tileNumber / (tileset.getSize().x / tileSize.x);
			sf::Vertex* quad = &map[(i + j * mapCols) * 4];
			// define its 4 corners
			quad[0].position = sf::Vector2f(float(i * tileSize.x), float(j * tileSize.y));
			quad[1].position = sf::Vector2f(float((i + 1) * tileSize.x),float(j * tileSize.y));
			quad[2].position = sf::Vector2f(float((i + 1) * tileSize.x), float((j + 1) * tileSize.y));
			quad[3].position = sf::Vector2f(float(i * tileSize.x), float((j + 1) * tileSize.y));

			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(float(tu * tileSize.x), float(tv * tileSize.y));
			quad[1].texCoords = sf::Vector2f(float((tu + 1) * tileSize.x),float( tv * tileSize.y));
			quad[2].texCoords = sf::Vector2f(float((tu + 1) * tileSize.x), float((tv + 1) * tileSize.y));
			quad[3].texCoords = sf::Vector2f(float(tu * tileSize.x), float((tv + 1) * tileSize.y));
		}
	state.texture = &tileset;
	this->player.movePlayer(this->winw / 2 - 32,this->winh / 2 - 32);
	mapX = -640;
	mapY = -448;
	//Adding towers for testing
	addTower(6, 0, 0);
	addTower(5, 64*1, 0);
	addTower(4, 64 * 2, 0);
	addTower(2, 64 * 3, 0);
	addTower(1, 64 * 4, 0);
	addTower(8, 64 * 5, 0);
	addTower(9, 64 * 6, 0);
	addTower(10, 64 * 7, 0);
	addTower(11, 64 * 8, 0);
	//shopKeepers
	addShopKeeper(7, 64 * 5, 64 * 10, 1);
	addShopKeeper(10, 64 * 7, 64 * 10, 1);
	//lives
	lives = 100;
}

Model::~Model() {
}

void Model::update(sf::Time delta) {
	//check for GameOver
	if (this->lives < 1) {
		this->gameMode = -1;
	}
	this->player.update(delta);
	sf::Transform mapState;
	mapState.translate(float(mapX), float(mapY));
	state.transform = mapState;
	for (unsigned int i = 0; i < this->enemies.size(); i++) {
		bool crossedLine = false;
		this->enemies.at(i).UpdatePos(this->mapX, this->mapY);
		if (checkPoint[-this->enemies.at(i).getPosition().x+mapX+640][-this->enemies.at(i).getPosition().y+mapY+448]) {
			if (this->enemies.at(i).checkPointUpdate(1)==0) {
				//spawns new enemy if there is a current save thats not over
			}
			if (this->enemies.at(i).checkPointUpdate(0) == 15) {
				this->lives -= 1;
				crossedLine = true;
			}
		}
		if (crossedLine) {
			//delete enemy here
		}
		else {
			this->enemies.at(i).update(delta);
		}
		//std::cout << mapX << ", " << mapY << " Player"<<std::endl;
	}
	for (unsigned int i = 0; i < this->towers.size(); i++) {
		if (this->towers.at(i).moving == false) {
			this->towers.at(i).moveTower(int(this->dispX), int(this->dispY));
		}
	}
	for (unsigned int i = 0; i < this->shops.size(); i++) {
		this->shops.at(i).movePlayer(int(this->dispX), int(this->dispY));
	}
	this->dispX = 0;
	this->dispY = 0;
}

bool Model::checkPlayerCollision(int direction) {
	/*
	0 == up
	1 == down
	2 == left
	3 == right
	*/
	for (int i = 0; i < 64; i++) {
		switch (direction) {
		case 0:
			if (unpassable[mapX + i][mapY + 64] || unpassable[mapX - i][mapY + 64]) {
				return true;
			}
			break;
		case 1:
			if (unpassable[mapX + i][mapY - 64] || unpassable[mapX - i][mapY - 64]) {
				return true;
			}
			break;
		case 2:
			if (unpassable[mapX + 64][mapY - i] || unpassable[mapX + 64][mapY + i]) {
				return true;
			}
			break;
		case 3:
			if (unpassable[mapX - 64][mapY - i] || unpassable[mapX - 64][mapY + i]) {
				return true;
			}
			break;
		}
	}
	return false;
}

int Model::talking(int direc) {
	//standing=1, walking down=2, walking left =3, walking right=4, walking up=5
	int diffY, diffX;
	switch (direc) {
	case 2:
		for (unsigned int i = 0; i < this->shops.size(); i++) {
			diffY = int(this->shops.at(i).positionPlayer().y - this->player.positionPlayer().y);
			if (diffY<96 && diffY>63) {
				diffX = int(this->shops.at(i).positionPlayer().x - this->player.positionPlayer().x);
				if (diffX<32 && diffX>-32) {
					return i;
				}
			}
		}
		break;
	case 3:
		for (unsigned int i = 0; i < this->shops.size(); i++) {
			diffY = int(this->shops.at(i).positionPlayer().y - this->player.positionPlayer().y);
			if (diffY<32 && diffY>-32) {
				diffX = int(this->shops.at(i).positionPlayer().x - this->player.positionPlayer().x);
				if (diffX>-96 && diffX<-63) {
					return i;
				}
			}
		}
		break;
	case 4:
		for (unsigned int i = 0; i < this->shops.size(); i++) {
			diffY = int(this->shops.at(i).positionPlayer().y - this->player.positionPlayer().y);
			if (diffY<32 && diffY>-32) {
				diffX = int(this->shops.at(i).positionPlayer().x - this->player.positionPlayer().x);
				if (diffX<96 && diffX>63) {
					return i;
				}
			}
		}
		break;
	case 5:
		for (unsigned int i = 0; i < this->shops.size(); i++) {
			diffY = int(this->shops.at(i).positionPlayer().y - this->player.positionPlayer().y);
			if (diffY>-96 && diffY<-63) {
				diffX = int(this->shops.at(i).positionPlayer().x - this->player.positionPlayer().x);
				if (diffX<32 && diffX>-32) {
					return i;
				}
			}
		}
		break;
	}
	return -1;
}

int Model::enterTower(int direc) {
	//standing=1, walking down=2, walking left =3, walking right=4, walking up=5
	//this->model->towers.at(i).positionTower().y + 64 > this->model->winh / 2-32
	int diffY, diffX;
	switch (direc) {
	case 2:
		for (unsigned int i = 0; i < this->towers.size(); i++) {
			diffY = int(this->towers.at(i).positionTower().y - this->player.positionPlayer().y);
			if (diffY<96 && diffY>63) {
				diffX= int(this->towers.at(i).positionTower().x - this->player.positionPlayer().x);
				if (diffX<32 && diffX>-32) {
					this->player.driving = true;
					this->player.inThisTower = i;
					this->towers.at(i).moving = true;
					this->mapX -= diffX;
					this->dispX -= diffX;
					this->mapY -= diffY;
					this->dispY -= diffY;
					this->towers.at(i).moveTower(-diffX, -diffY);
					unpassable[mapX][mapY] = false;
					return 1;
				}
			}
		}
		break;
	case 3:
		for (unsigned int i = 0; i < this->towers.size(); i++) {
			diffY = int(this->towers.at(i).positionTower().y - this->player.positionPlayer().y);
			if (diffY<32 && diffY>-32) {
				diffX = int(this->towers.at(i).positionTower().x - this->player.positionPlayer().x);
				if (diffX>-96 && diffX<-63) {
					this->player.driving = true;
					this->player.inThisTower = i;
					this->towers.at(i).moving = true;
					this->mapX -= diffX;
					this->dispX -= diffX;
					this->mapY -= diffY;
					this->dispY -= diffY;
					this->towers.at(i).moveTower(-diffX, -diffY);
					unpassable[mapX][mapY] = false;
					return 1;
				}
			}
		}
		break;
	case 4:
		for (unsigned int i = 0; i < this->towers.size(); i++) {
			diffY = int(this->towers.at(i).positionTower().y - this->player.positionPlayer().y);
			if (diffY<32 && diffY>-32) {
				diffX = int(this->towers.at(i).positionTower().x - this->player.positionPlayer().x);
				if (diffX<96 && diffX>63) {
					std::cout << "enter right" << std::endl;
					this->player.driving = true;
					this->player.inThisTower = i;
					this->towers.at(i).moving = true;
					this->mapX -= diffX;
					this->dispX -= diffX;
					this->mapY -= diffY;
					this->dispY -= diffY;
					this->towers.at(i).moveTower(-diffX, -diffY);
					std::cout << mapX << ", " << mapY << std::endl;
					unpassable[mapX][mapY] = false;
					return 1;
				}
			}
		}
		break;
	case 5:
		for (unsigned int i = 0; i < this->towers.size(); i++) {
			diffY = int(this->towers.at(i).positionTower().y - this->player.positionPlayer().y);
			if (diffY>-96 && diffY<-63) {
				diffX = int(this->towers.at(i).positionTower().x - this->player.positionPlayer().x);
				if (diffX<32 && diffX>-32) {
					std::cout << "enter up" << std::endl;
					this->player.driving = true;
					this->player.inThisTower = i;
					this->towers.at(i).moving = true;
					this->mapX -= diffX;
					this->dispX -= diffX;
					this->mapY -= diffY;
					this->dispY -= diffY;
					this->towers.at(i).moveTower(-diffX, -diffY);
					//std::cout << mapX << "," << mapY << std::endl;
					unpassable[mapX][mapY] = false;
 					return 1;
				}
			}
		}
		break;
	}
	return 0;
}
void Model::addTower(int which, int xx, int yy) {
	Tower temp(which, xx, yy);
	this->towers.push_back(temp);
	unpassable[-xx-32][yy] = true;
}
void Model::addTower(int which)
{
	float xx, yy;
	if (this->shops.at(1).direction == 1) {
		xx = this->shops.at(1).positionPlayer().x;
		yy = this->shops.at(1).positionPlayer().y - 64 * 2;
	}
	else if (this->shops.at(1).direction == 2) {
		xx = this->shops.at(1).positionPlayer().x + 64 * 3;
		yy = this->shops.at(1).positionPlayer().y;
	}
	else if (this->shops.at(1).direction == 3) {
		xx = this->shops.at(1).positionPlayer().x;
		yy = this->shops.at(1).positionPlayer().y + 64 * 3;
	}
	else {
		xx = this->shops.at(1).positionPlayer().x - 64 * 2;
		yy = this->shops.at(1).positionPlayer().y;
	}
	Tower temp(which, int(xx), int(yy));
	this->towers.push_back(temp);
	std::cout << xx << "," << yy << std::endl;
	unpassable[-xx - 32][yy] = true;
}
void Model::addShopKeeper(int which, int xx, int yy, int dir)
{
	ShopKeeper temp(which, xx, yy, dir);
	this->shops.push_back(temp);
	std::cout << xx - 32 << "," << yy << std::endl;
	unpassable[-xx - 32][yy] = true;
}
void Model::addEnemy(int which) {
	Enemy temp(which);
	this->enemies.push_back(temp);
}

void Model::exitTower(){
	this->towers.at(this->player.inThisTower).moving = false;
	unpassable[mapX][mapY] = true;
	this->player.driving = false;
	this->player.inThisTower = -1;
}
