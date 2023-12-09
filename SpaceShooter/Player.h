#pragma once
#include <iostream>

#include "SFML\Graphics.hpp"
#include "SFML\System.hpp"

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	float movementSpeed;

	//Private functions:
	void initTexture();
	void initSprite();

public:
	Player();
	virtual ~Player();

	//Accessors / Getters
	const sf::Vector2f& getPosition() const;

	//Functions:
	void move(const float directionX, const float directionY);
	void update();
	void render(sf::RenderTarget& target);

};

