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
	Bullet(sf::Texture* texture, float posX, float posY, float directionX, float directionY, float movementSpeed);
	virtual ~Bullet();

	//Accessors / Getters
	sf::FloatRect getBounds() const;

	void update();
	void render(sf::RenderTarget* target);
};

