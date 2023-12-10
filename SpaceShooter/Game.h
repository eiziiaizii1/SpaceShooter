#pragma once

#include <string>
#include <sstream>
#include <map>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
//#include "SFML\Window.hpp"
//#include "SFML\Audio.hpp"

class Game
{
private:
	//WINDOW
	sf::RenderWindow* window;

	//RESOURCES
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	//GUI
	sf::Font font;
	sf::Text pointText;

	//WORLD
	sf::Texture worldTexture;
	sf::Sprite worldBackground;

	//SYSTEMS
	unsigned int points;

	//PLAYER
	Player* player;

	//PLAYER GUI
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;

	//ENEMIES
	std::vector<Enemy*> enemies;
	float spawnTimer;
	float spawnTimerMax;

	//Private Functions:
	void initWindow();
	void initTextures();
	void initGUI();
	void initWorldBG();
	void initSystems();

	void initPlayer();
	void initEnemies();

public:
	Game();
	virtual ~Game();

	//Functions:
	void run();

	void updatePollEvent();
	void updatePlayerInput();
	void updateGUI();
	void updateWorld();
	void updateCollision();
	void updateBullets();
	void updateEnemies();
	void updateCombat();
	void update();

	void renderWorld();
	void renderGUI();
	void render();
};

