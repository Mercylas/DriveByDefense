#include "Enemy.h"



Enemy::Enemy(int type)
{
	this->frameRate = float(0.6);
	this->type = type;
	this->checkpoint = 0;
	switch (type) {
	case 1:
		this->texSheet.loadFromFile("Assets/Assets/enemies/Enemy1.png"); //32x32
		this->health = 100;
		break;
	default:
		this->texSheet.loadFromFile("Assets/Assets/enemies/Enemy1.png"); //32x32
		this->health = 100;
		break;
	}
	addFrame(sf::IntRect(0, 2, 64, 64));
	addFrame(sf::IntRect(64, 2, 64, 64));
	addFrame(sf::IntRect(128, 2, 64, 64));
	//walk down
	addFrame(sf::IntRect(0, 66, 64, 64));
	addFrame(sf::IntRect(64, 66, 64, 64));
	addFrame(sf::IntRect(128, 66, 64, 64));
	//walk left
	addFrame(sf::IntRect(0, 130, 64, 64));
	addFrame(sf::IntRect(64, 130, 64, 64));
	addFrame(sf::IntRect(128, 130, 64, 64));
	//walk right
	addFrame(sf::IntRect(0, 194, 64, 64));
	addFrame(sf::IntRect(64, 194, 64, 64));
	addFrame(sf::IntRect(128, 194, 64, 64));
	//walk up
	this->state = 1;
	this->sequenceIndex = 0;
	this->frameTime = 0;
	this->vertices.setPrimitiveType(sf::Quads);
	this->vertices.resize(4);
	sf::Vertex* quad = &this->vertices[0];
	quad[0].position = sf::Vector2f(float(0), float(0));
	quad[1].position = sf::Vector2f(float(64), float(0));
	quad[2].position = sf::Vector2f(float(64), float(64));
	quad[3].position = sf::Vector2f(float(0), float(64));

	quad[0].texCoords = sf::Vector2f(float(this->playerFrames.at(this->sequenceIndex).left), float(this->playerFrames.at(this->sequenceIndex).top));
	quad[1].texCoords = sf::Vector2f(float(this->playerFrames.at(this->sequenceIndex).width), float(this->playerFrames.at(this->sequenceIndex).top));
	quad[2].texCoords = sf::Vector2f(float(this->playerFrames.at(this->sequenceIndex).width), float(this->playerFrames.at(this->sequenceIndex).height));
	quad[3].texCoords = sf::Vector2f(float(this->playerFrames.at(this->sequenceIndex).left), float(this->playerFrames.at(this->sequenceIndex).height));
	this->posX = 0;
	this->posY = 0;
}


Enemy::~Enemy()
{
	this->state = 2;
}

void Enemy::update(sf::Time delta)
{
	this->frameTime += delta.asSeconds();
	if (this->frameTime > this->frameRate) {
		if (this->sequenceIndex % 3 == 2) {
			this->sequenceIndex -= 2;
			setTexCord();
			this->frameTime = 0;
		}
		else {
			this->sequenceIndex++;
			setTexCord();
			this->frameTime = 0;
		}
	}
}

void Enemy::setTexCord()
{
	sf::Vertex* quad = &this->vertices[0];
	int here = this->sequenceIndex - 3 + 3 * this->state;
	quad[0].texCoords = sf::Vector2f(float(this->playerFrames.at(here).left), float(this->playerFrames.at(here).top));
	quad[1].texCoords = sf::Vector2f(float(this->playerFrames.at(here).left + this->playerFrames.at(here).width), float(this->playerFrames.at(here).top));
	quad[2].texCoords = sf::Vector2f(float(this->playerFrames.at(here).left + this->playerFrames.at(here).width), float(this->playerFrames.at(here).top + this->playerFrames.at(here).height));
	quad[3].texCoords = sf::Vector2f(float(this->playerFrames.at(here).left), float(this->playerFrames.at(here).top + this->playerFrames.at(here).height));
}

void Enemy::addFrame(sf::IntRect rect)
{
	this->playerFrames.push_back(rect);
}

void Enemy::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();		// apply the transform
	states.texture = &this->texSheet;		// apply the tileset texture
	target.draw(this->vertices, states);	// draw the vertex array
}

bool Enemy::isDead() {
	return (health < 1);
}

void Enemy::UpdatePos(int mapX, int mapY) {
	mapX += 3776 - 32;
	mapY += 896;
	this->setPosition(this->posX + mapX, this->posY + mapY);
}