#include "Game.h"

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1400,900), "SpaceShooter", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void Game::initTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("Textures/Bullet.png");
}

void Game::initPlayer()
{
	this->player = new Player();
}

Game::Game()
{
	this->initWindow();
	this->initTextures();
	this->initPlayer();
}

Game::~Game()
{
	delete this->window;
	delete this->player;

	//DELETE TEXTURES
	for (auto i : this->textures) 
	{
		//deletes the 2nd elements of the map which are textures
		delete i.second;
	}

	//Delete Bullets
	for (auto *i : this->bullets)
	{
		delete i;
	}
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

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack()) 
	{
		this->bullets.push_back(new Bullet(this->textures["BULLET"],
			this->player->getPosition().x, this->player->getPosition().y, 0.f, -1.f, 5.f));
	}
}

void Game::updateBullets()
{
	unsigned int counter = 0;
	for(auto *bullet: this->bullets)
	{
		bullet->update();

		//Bullet culling (top of the screen)
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
		{
			//Delete Bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;

		}

		++counter;
	}
}

void Game::update()
{
	this->updatePollEvent();

	this->updatePlayerInput();

	this->player->update();

	this->updateBullets();
}

void Game::render()
{
	this->window->clear();
	//--------------------------------------------------------
	//     Draw things in here:    // 

	this->player->render(*this->window);

	//Render Bullets
	for (auto *bullet: this->bullets) 
	{
		bullet->render(this->window);
	}


	//--------------------------------------------------------
	this->window->display();
}
