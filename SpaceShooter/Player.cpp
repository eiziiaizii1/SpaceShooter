#include "Player.h"

void Player::initTexture()
{
	//LOAD TEXTURE FROM FILE
}

void Player::initSprite()
{
	//SET THE TEXTURE TO THE SPRITE
	this->sprite.setTexture(this->texture);
}

Player::Player()
{
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{

}


//Functions:
void Player::update()
{

}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
