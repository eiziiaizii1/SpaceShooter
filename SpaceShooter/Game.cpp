#include "Game.h"

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1400,900), "SpaceShooter", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void Game::initTextures()
{
	
}

void Game::initPlayer()
{
	this->player = new Player();
}

Game::Game()
{
	this->initWindow();
	this->initPlayer();
}

Game::~Game()
{
	delete this->window;
	delete this->player;
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

void Game::updatePollEvent()
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

void Game::updatePlayerInput()
{
	//MOVE PLAYER
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->player->move(-1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->player->move(1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->player->move(0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->player->move(0.f, 1.f);
	}
}

void Game::update()
{
	this->updatePollEvent();

	this->updatePlayerInput();
}

void Game::render()
{
	this->window->clear();
	//--------------------------------------------------------
	//Draw things in here
	this->player->render(*this->window);


	//--------------------------------------------------------
	this->window->display();
}
