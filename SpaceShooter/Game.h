#pragma once

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

	//PLAYER
	Player* player;

	//ENEMIES
	std::vector<Enemy*> enemies;
	float spawnTimer;
	float spawnTimerMax;

	//Private Functions:
	void initWindow();
	void initTextures();
	void initGUI();

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
	void updateBullets();
	void updateEnemies();
	void updateCombat();
	void update();

	void renderGUI();
	void render();
};

