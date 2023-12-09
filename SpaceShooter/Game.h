#pragma once
#include "Player.h"
//#include "SFML\Window.hpp"
//#include "SFML\Audio.hpp"

class Game
{
private:
	sf::RenderWindow* window;

	//PLAYER
	Player* player;

	//Private Functions:
	void initWindow();
	void initPlayer();

public:
	Game();
	virtual ~Game();

	//Functions:
	void run();

	void update();
	void render();
};

