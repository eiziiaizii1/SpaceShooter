#include "Enemy.h"

void Enemy::initShape()
{
	this->shape.setRadius(rand()% 20 + 21);
	this->shape.setPointCount(rand() % 20 + 3);
	this->shape.setFillColor(sf::Color(rand() % 255 + 1,rand() % 255 + 1, rand() % 255 + 1,255));
}

void Enemy::initVariables()
{
	this->type		= 0;
	this->hpMax		= 10;
	this->hp		= 0;
	this->damage	= 1;
	this->points	= 5;
}

Enemy::Enemy()
{
}

Enemy::Enemy(float posX, float posY)
{
	this->initShape();
	this->initVariables();
	this->shape.setPosition(posX, posY);
}

Enemy::~Enemy()
{
}

const sf::FloatRect Enemy::getBounds() const
{
	return this->shape.getGlobalBounds();
}

//FUNCTIONS:
void Enemy::update()
{
	this->shape.move(0.f, 20.f);
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
