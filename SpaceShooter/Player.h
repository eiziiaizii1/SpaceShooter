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

	float attackCooldown;
	float attackCooldownMax;

	//Private functions:
	void initVariables();
	void initTexture();
	void initSprite();

public:
	Player();
	virtual ~Player();

	//Accessors / Getters
	const sf::Vector2f& getPosition() const;
	const sf::FloatRect getGlobalBounds() const;

	//Functions:
	void move(const float directionX, const float directionY);
	const bool canAttack();

	void updateAttack();
	void update();
	void render(sf::RenderTarget& target);

};

