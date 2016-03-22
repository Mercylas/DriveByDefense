#include "Controller.hpp"

Controller::Controller(Model * m, View * v) {
	this->model = m;
	this->view = v;
	this->ready = true;
	start();
}

Controller::~Controller() {
}

void Controller::inputs() {
	sf::Event event;

	while (this->view->window.pollEvent(event))
	{
		switch (event.type)
		{
			// window closed
		case sf::Event::Closed:
			this->view->window.close();
			break;
			// key pressed
		case sf::Event::KeyPressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
				this->view->window.close();
				break;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				if (!model->checkPlayerCollision(0)) {
					if (this->model->player.driving) {
						model->mapY += 8;
						model->dispY += 8;
					}
					else {
						model->mapY += 4;
						model->dispY += 4;
					}
				}
				model->player.state = 5;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				if (!model->checkPlayerCollision(1)) {
					if (this->model->player.driving) {
						model->mapY -= 8;
						model->dispY -= 8;
					}
					else {
						model->mapY -= 4;
						model->dispY -= 4;
					}
				}
				model->player.state = 2;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				if (!model->checkPlayerCollision(2)) {
					if (this->model->player.driving) {
						model->mapX += 8;
						model->dispX += 8;
					}
					else {
						model->mapX += 4;
						model->dispX += 4;
					}
				}
				model->player.state = 3;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				if (!model->checkPlayerCollision(3)) {
					if (this->model->player.driving) {
						model->mapX -= 8;
						model->dispX -= 8;
					}
					else {
						model->mapX -= 4;
						model->dispX -= 4;
					}
				}
				model->player.state = 4;
			}
			break;
			//Key Released
		case sf::Event::KeyReleased:
			model->player.state = 1;
			this->ready = true;
			break;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
			this->model->addEnemy(1);
			std::cout << "hey" << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			if (this->ready) {
				if (this->model->player.driving) {
					this->model->exitTower();
				}
				else {
					this->model->enterTower(this->model->player.state);
				}
				this->ready = false;
			}
		}
	}
}
void Controller::start() {
	std::cout << "-------- Drive By Defense -------" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	while (model->gameMode != 1 || model->gameMode != 2) {
		std::cout << "------ Choose a game type -------" << std::endl;
		std::cout << "1. Sandbox" << std::endl;
		std::cout << "---------------------------------" << std::endl;
		std::cin >> model->gameMode;
		if (std::cin.fail() || !(model->gameMode >= 1 && model->gameMode <= 2))
		{
			std::cout << "invalid selection!" << std::endl;
			std::cout << "selection: " << std::endl;
			std::cout << "---------------------------------" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
		}
		if (model->gameMode == 1 || model->gameMode == 2) {
			std::cout << "-------- Enjoy the game! --------" << std::endl;
			std::cout << "---------------------------------" << std::endl;
			break;
		}
		std::cout << "You entered: " << model->gameMode << std::endl;
		std::cout << "That is not a valid input! " << model->gameMode << std::endl;
		std::cout << "---------------------------------" << std::endl;
	}
}