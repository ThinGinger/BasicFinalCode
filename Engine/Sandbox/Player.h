#pragma once

#include <GameObject.h>
#include <string>
class Player : public scene::GameObject
{
public:
	Player (std::string path);
	~Player ();
};