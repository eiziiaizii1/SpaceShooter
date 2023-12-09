#include "Game.h"

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1400,900), "SpaceShooter", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

Game::Game()
{
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}


//Functions:
void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

void Game::update()
{
	sf::Event ev;
	while (this->window->pollEvent(ev))
	{
		switch (ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
				break;
			}
		}
	}
}

void Game::render()
{
	this->window->clear();
	//--------------------------------------
	//Draw things in here



	//--------------------------------------
	this->window->display();
}
