#include "Bullet.h"

Bullet::~Bullet()
{
}

Bullet::Bullet()
{
	transform.x = 0;
	transform.y = 0;
	transform.w = 100;
	transform.h = 100;
}

Bullet::Bullet(std::string path, int x_, int y_) : GameObject(path)
{
	transform.x = x_;
	transform.y = y_;
	transform.w = 100;
	transform.h = 100;
	ySpeed = -2;
}