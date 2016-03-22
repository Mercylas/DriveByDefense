#include "Tower.hpp"

Tower::Tower()
{
}

Tower::Tower(int which, int xx, int yy) {
	this->texSheet.loadFromFile("Assets/Assets/towers/Towers.png"); //64x128
	this->vertices.setPrimitiveType(sf::Quads);
	this->vertices.resize(4);
	this->moving = false;
	this->type = which;
	sf::Vertex* quad = &this->vertices[0];
	quad[0].position = sf::Vector2f(float(xx), float(yy));
	quad[1].position = sf::Vector2f(float(xx + 64), float(yy));
	quad[2].position = sf::Vector2f(float(xx + 64), float(yy + 64));
	quad[3].position = sf::Vector2f(float(xx), float(yy + 64));

	quad[0].texCoords = sf::Vector2f(float((which - 1) * 64), float(0));
	quad[1].texCoords = sf::Vector2f(float(which * 64), float(0));
	quad[2].texCoords = sf::Vector2f(float(which * 64), float(128));
	quad[3].texCoords = sf::Vector2f(float((which - 1) * 64), float(128));
}

Tower::~Tower() {
}

void Tower::moveTower(int xx, int yy) {
	sf::Vertex* quad = &this->vertices[0];
	quad[0].position = sf::Vector2f(float(quad[0].position.x + xx), float(quad[0].position.y + yy));
	quad[1].position = sf::Vector2f(float(quad[1].position.x + xx), float(quad[1].position.y + yy));
	quad[2].position = sf::Vector2f(float(quad[2].position.x + xx), float(quad[2].position.y + yy));
	quad[3].position = sf::Vector2f(float(quad[3].position.x + xx), float(quad[3].position.y + yy));
}

sf::Vector2f Tower::positionTower() {
	sf::Vertex* quad = &this->vertices[0];
	return quad[0].position;
}

void Tower::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();		// apply the transform
	states.texture = &this->texSheet;		// apply the tileset texture
	target.draw(this->vertices, states);	// draw the vertex array
}
