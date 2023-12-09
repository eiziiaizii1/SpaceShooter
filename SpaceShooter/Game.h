#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\System.hpp"
//#include "SFML\Window.hpp"
//#include "SFML\Audio.hpp"

class Game
{
private:
	sf::RenderWindow* window;

	//Private Functions:
	void initWindow();

public:
	Game();
	virtual ~Game();

	//Functions:
	void run();

	void update();
	void render();
};

