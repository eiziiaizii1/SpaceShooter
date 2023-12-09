#include "Bullet.h"



Bullet::Bullet()
{
}

Bullet::Bullet(sf::Texture* texture, float posX, float posY, float directionX, float directionY, float movementSpeed)
{
	this->shape.setTexture(*texture);

	this->shape.setPosition(posX, posY );
	this->shape.scale(0.5f,0.4f);
	this->direction.x = directionX;
	this->direction.y = directionY;
	this->movementSpeed = movementSpeed;
}

Bullet::~Bullet()
{

}

sf::FloatRect Bullet::getBounds() const
{
	return this->shape.getGlobalBounds();
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
