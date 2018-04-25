#include <iostream>
#include <Engine.h>

#include "MainScene.h"

int main (int argc, char* args[])
{
	using namespace core;

	Engine e(new MainScene());
	if (e.init () == 0)
	{
		return e.run ();
	}

	return -1;
}