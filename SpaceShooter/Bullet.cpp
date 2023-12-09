#include "Bullet.h"



Bullet::Bullet()
{
}

Bullet::Bullet(sf::Texture& texture, float directionX, float directionY, float movementSpeed)
{
	this->shape.setTexture(texture);
	this->direction.x = directionX;
	this->direction.y = directionY;
	this->movementSpeed = movementSpeed;
}

Bullet::~Bullet()
{

}

void Bullet::update()
{
	//MOVEMENT
	this->shape.move(this->movementSpeed * this->direction);
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
