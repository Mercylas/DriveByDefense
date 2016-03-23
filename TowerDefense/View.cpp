#include "View.hpp"
View::View(Model * m) {
	this->model = m;
	this->window.create(sf::VideoMode(this->model->winw, this->model->winh), "Assignment 3");
	this->loadPlayerText();
	this->loadTowerText();
	this->loadShopKeepText();
	this->loadPowerUps();
	this->talking = false;
	this->model->player.setTextSheet(&this->playerText);
	for (unsigned int i = 0; i < this->model->towers.size(); i++) {
		this->model->towers.at(i).setTowerText(&this->towersText);
	}
	for (unsigned int i = 0; i < this->model->shops.size(); i++) {
		this->model->shops.at(i).setTextSheet(&this->shopKeeperText);
	}
	for (unsigned int i = 0; i < this->model->powerUps.size(); i++) {
		this->model->powerUps.at(i).setTextSheet(&this->powerUpsText);
	}
	this->fonterino.loadFromFile("Assets/Vecna.otf");
	this->sell.setCharacterSize(50);
	this->sell.setPosition(20, 610);
	this->sell.setColor(sf::Color(0, 0, 0, 255));
	this->sell.setFont(this->fonterino);
	this->sell.setString(this->model->shops.at(0).shopMenu);
	this->gold.setCharacterSize(30);
	this->gold.setPosition(10, 5);
	this->gold.setColor(sf::Color(0, 0, 0, 150));
	this->gold.setFont(this->fonterino);
	this->towerInfo.setCharacterSize(30);
	this->towerInfo.setPosition(10, 300);
	this->towerInfo.setColor(sf::Color(0, 0, 0, 150));
	this->towerInfo.setFont(this->fonterino);
}

View::~View() {
}

void View::render() {
	this->window.clear(sf::Color::Black);
	//put stuff here to draw for example, object->renderable()
	//go through the tiles and only draw the one we need
	this->gold.setString("Lives: "+std::to_string(this->model->lives) + "\n" + this->model->player.inventory.returnPowerUpAmount() +"\n"+this->model->player.inventory.returnGoldAmount());
	this->window.draw(model->map, model->state);
	for (unsigned int i = 0; i < this->model->powerUps.size(); i++) {
		this->window.draw(this->model->powerUps.at(i));
	}
	for (unsigned int i = 0; i < this->model->towers.size(); i++) {
		this->window.draw(this->model->towers.at(i));
	}
	for (unsigned int i = 0; i < this->model->shops.size(); i++) {
		this->window.draw(this->model->shops.at(i));
	}
	for (unsigned int i = 0; i < this->model->enemies.size(); i++) {
		this->window.draw(this->model->enemies.at(i));
	}
	if (this->model->player.driving == false) {
		this->window.draw(this->model->player);
	}
	else {
		this->towerInfo.setString(this->model->towers.at(this->model->player.inThisTower).getTowerStats());
		this->window.draw(this->towerInfo);
	}
	if (this->talking) {
		this->window.draw(this->dialogueBox);
		this->window.draw(this->sell);
	}
	this->window.draw(this->gold);
	this->window.display();
}

void View::loadPlayerText()
{
	this->playerText.loadFromFile("Assets/Assets/player/Character.png");
}

void View::loadTowerText()
{
	this->towersText.loadFromFile("Assets/Assets/towers/Towers.png");
}

void View::loadShopKeepText()
{
	this->shopKeeperText.loadFromFile("Assets/Assets/Allies/Spiritual.png");
}

void View::loadPowerUps(){
	this->powerUpsText.loadFromFile("Assets/Assets/towers/powerUps.png");
}

void View::setNewTowerTexture() {
	this->model->towers.at(this->model->towers.size()-1).setTowerText(&this->towersText);
}

void View::setNewPowerUpTexture(){
	this->model->powerUps.at(this->model->powerUps.size() - 1).setTextSheet(&this->powerUpsText);
}

void View::setText(int who) {
	this->sell.setString(this->model->shops.at(who).shopMenu);
}
