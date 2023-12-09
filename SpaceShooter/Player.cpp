#include "Player.h"

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
	this->movementSpeed = 10.f;

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

//Functions:
void Player::update()
{

}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
