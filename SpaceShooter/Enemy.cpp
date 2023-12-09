#include "Enemy.h"

void Enemy::initShape()
{
	this->shape.setRadius(rand()% 20 + 21);
	this->shape.setPointCount(rand() % 20 + 3);
}

void Enemy::initVariables()
{
	this->type		= 0;
	this->hp		= 0;
	this->hpMax		= 10;
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

//FUNCTIONS:
void Enemy::update()
{

}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
