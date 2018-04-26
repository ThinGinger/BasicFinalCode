#pragma once

#include <GameObject.h>
#include <string>
class Bullet : public scene::GameObject
{
public:
	Bullet();
	Bullet(std::string path);
	Bullet(std::string path, int x_, int y_);

	~Bullet();
};