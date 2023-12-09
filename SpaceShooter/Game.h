#pragma once

#include <map>
#include "Player.h"
//#include "SFML\Window.hpp"
//#include "SFML\Audio.hpp"

class Game
{
private:
	//WINDOW
	sf::RenderWindow* window;

	//RESOURCES
	std::map<std::string, sf::Texture> textures;

	//PLAYER
	Player* player;

	//Private Functions:
	void initWindow();
	void initTextures();

	void initPlayer();

public:
	Game();
	virtual ~Game();

	//Functions:
	void run();

	void updatePollEvent();
	void updatePlayerInput();
	void update();
	void render();
};

