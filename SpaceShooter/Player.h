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

	int hp;
	int hpMax;

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
	const int getHp() const;
	const int getHpMax() const;

	//Setters
	void setPosition(const sf::Vector2f position);
	void setPosition(const float x, const float y);
	void setHp(const int hp);
	void loseHp(const int value);

	//Functions:
	void move(const float directionX, const float directionY);
	const bool canAttack();

	void updateAttack();
	void update();
	void render(sf::RenderTarget& target);

};

