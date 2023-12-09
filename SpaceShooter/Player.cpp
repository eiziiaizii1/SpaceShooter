#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 2.f;
	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;
}

void Player::initTexture()
{
	//LOAD TEXTURE FROM FILE
	if (!this->texture.loadFromFile("Textures/SpaceShip.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE()::Couldn't load the ship's texture" << std::endl;
	}
}

void Player::initSprite()
{
	//SET THE TEXTURE TO THE SPRITE
	this->sprite.setTexture(this->texture);

	//Resize the texture (DEFAULT SIZE IS ACTUALLY OK)
	this->sprite.scale(1.0f,1.0f);
}

Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{

}

const sf::Vector2f& Player::getPosition() const
{
	return this->sprite.getPosition();
}


void Player::move(const float directionX, const float directionY)
{
	this->sprite.move(this->movementSpeed * directionX, this->movementSpeed * directionY);
}

const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}

void Player::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax) 
	{
		this->attackCooldown += 1.f;
	}
}

//Functions:
void Player::update()
{
	this->updateAttack();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
