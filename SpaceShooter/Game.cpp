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

void Game::initEnemies()
{
	this->spawnTimerMax = 50.f;
	this->spawnTimer = this->spawnTimerMax;
}

Game::Game()
{
	this->initWindow();
	this->initTextures();
	this->initPlayer();
	this->initEnemies();
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

	//DELETE BULLETS
	for (auto *i : this->bullets)
	{
		delete i;
	}

	//DELETE ENEMIES
	for (auto *enemy: this->enemies) 
	{
		delete enemy;
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
		this->bullets.push_back(
			new Bullet
			(this->textures["BULLET"],
			this->player->getPosition().x + (this->player->getGlobalBounds().width / 2) - 36,
			this->player->getPosition().y - 48, 
			0.f, -1.f, 5.f)
		);
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

void Game::updateEnemies()
{
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= spawnTimerMax) 
	{
		this->enemies.push_back(new Enemy(rand() % this->window->getSize().x, -100.f));
		this->spawnTimer = 0.f;
	}

	for (int i = 0; i < this->enemies.size(); ++i)
	{
		this->enemies[i]->update();

		//Enemy culling at the bottom
		if (this->enemies[i]->getBounds().top > this->window->getSize().y)
		{
			this->enemies.erase(this->enemies.begin() + i);
			std::cout << this->enemies.size() << std::endl;
		}
	}
}

void Game::update()
{
	this->updatePollEvent();

	this->updatePlayerInput();

	this->player->update();

	this->updateBullets();

	this->updateEnemies();
}

void Game::render()
{
	this->window->clear();
	//--------------------------------------------------------
	//     Draw things in here:    // 

	//Render the player
	this->player->render(*this->window);

	//Render Bullet
	for (auto *bullet: this->bullets) 
	{
		bullet->render(this->window);
	}

	//Render enemies
	for (auto *enemy : enemies)
	{
		enemy->render(this->window);
	}

	//--------------------------------------------------------
	this->window->display();
}
