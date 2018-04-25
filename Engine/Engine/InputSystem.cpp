#include "InputSystem.h"

#include <SDL.h>
#include <iostream>
namespace core
{
	InputSystem::InputSystem () :
		System (SystemType::INPUT),
		quitResquested(false)
	{
	}


	InputSystem::~InputSystem ()
	{
	}

	void InputSystem::update ()
	{
		//Event handler
		SDL_Event e;

		//Handle events on queue
		while (SDL_PollEvent (&e) != 0)
		{
			switch (e.type)
			{
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym)
				{
				case SDLK_LEFT:
					m_leftPressed = true;
					break;
				case SDLK_RIGHT:
					m_rightPressed = true;
					break;
				}
				break;
			case SDL_KEYUP:
				switch (e.key.keysym.sym)
				{
				case SDLK_LEFT:
					m_leftPressed = false;
					break;
				case SDLK_RIGHT:
					m_rightPressed = false;
					break;
				}
				break;
			case SDL_QUIT:
				quitResquested = true;
				break;
			}
		}
	}
}
