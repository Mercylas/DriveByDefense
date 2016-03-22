#include "View.hpp"
View::View(Model * m) {
	this->model = m;
	this->window.create(sf::VideoMode(this->model->winw, this->model->winh), "Assignment 3");
	this->window.setFramerateLimit(60);
}

View::~View() {
}

void View::render() {
	this->window.clear(sf::Color::Black);
	//put stuff here to draw for example, object->renderable()
	//go through the tiles and only draw the one we need
	this->window.draw(model->map, model->state);
	if (this->model->player.driving == false) {
		this->window.draw(this->model->player);
	}
	for (unsigned int i = 0; i < this->model->towers.size(); i++) {
		this->window.draw(this->model->towers.at(i));
	}
	for (unsigned int i = 0; i < this->model->enemies.size(); i++) {
		this->window.draw(this->model->enemies.at(i));
	}
	this->window.display();
}
