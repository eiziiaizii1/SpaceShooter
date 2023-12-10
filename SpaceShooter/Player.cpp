#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 7.5f;
	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;
	
	this->hpMax = 100;
	this->hp = hpMax;
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

const sf::FloatRect Player::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int Player::getHp() const
{
	return this->hp;
}

const int Player::getHpMax() const
{
	return this->hpMax;
}

void Player::setPosition(const sf::Vector2f position)
{
	this->sprite.setPosition(position);
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Player::setHp(const int hp)
{
	this->hp = hp;
}

void Player::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0) 
	{
		this->hp = 0;
	}
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
