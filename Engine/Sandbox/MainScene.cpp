#include "MainScene.h"

#include <Engine.h>
#include <SystemManager.h>
#include <InputSystem.h>
#include <iostream>
#include "Player.h"
#include <SDL.h>

MainScene::MainScene () :
	player("player.bmp")
{
}


MainScene::~MainScene ()
{
}

bool MainScene::init ()
{
	inputSystem = dynamic_cast<core::InputSystem*>(core::SystemManager::GetInstance ()->GetSystem (core::SystemType::INPUT));

	return true;
}

void MainScene::update ()
{
	if (inputSystem->IsLeftPressed ())
		player.transform.x -= 1;

	if (inputSystem->IsRightPressed ())
		player.transform.x += 1;

	// TODO check for up and down

	if (inputSystem->IsDownPressed())
		player.transform.y += 1;

	if (inputSystem->IsUpPressed())
		player.transform.y -= 1;

	
	// draw the player
	SDL_Surface *windowSurface = engine->getSurface ();
	// notice the function to draw the player scaled down
	SDL_BlitSurface (player.objectImage, NULL, windowSurface, &player.transform);
}

void MainScene::draw () const
{
	SDL_UpdateWindowSurface (engine->getWindow());
}

bool MainScene::shutdown ()
{
	return true;
}