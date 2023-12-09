#pragma once

#include <iostream>
#include "SFML\Graphics.hpp"

class Bullet
{
private:
	sf::Sprite shape;

	sf::Vector2f direction;
	float movementSpeed;
public:
	Bullet();
	Bullet(sf::Texture& texture, float directionX, float directionY, float movementSpeed);
	virtual ~Bullet();

	void update();
	void render(sf::RenderTarget* target);
};

