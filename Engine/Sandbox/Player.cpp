#include "Player.h"

Player::Player (std::string path) : GameObject(path)
{
	transform.x = 10;
	transform.y = 10;
	transform.w = 100;
	transform.h = 100;
}

Player::~Player ()
{

}