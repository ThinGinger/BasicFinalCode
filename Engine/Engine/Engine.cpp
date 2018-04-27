#include "Engine.h"
#include "Scene.h"
#include <iostream>

SDL_Surface* screenSurface = NULL;
SDL_Surface * image = NULL;
SDL_Rect *ImageRect = new SDL_Rect;

namespace core
{
	Engine::Engine (scene::Scene* s) :
		mainScene(s),
		isRunning(false)
	{
		managers.push_back (SystemManager::GetInstance());

		mainScene->engine = this;
	}

	Engine::~Engine ()
	{
		for (Manager *m : managers)
		{
			delete m;
			m = nullptr;
		}

		managers.clear ();
	}

	int Engine::init ()
	{
		int initResult = 0;

		//Initialize SDL
		if (SDL_Init (SDL_INIT_EVERYTHING) < 0)
		{
			printf ("SDL could not initialize! SDL_Error: %s\n", SDL_GetError ());

			initResult = ENGINE_INIT_ERROR;
		}
		else
		{
			image = SDL_LoadBMP("Background.bmp");
			//Create window
			window = SDL_CreateWindow ("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
			if (window == NULL)
			{
				printf ("Window could not be created! SDL_Error: %s\n", SDL_GetError ());

				initResult = ENGINE_INIT_ERROR;
			}
			else
			{
				//Get window surface
				screenSurface = SDL_GetWindowSurface (window);

				//Wait two seconds
				//SDL_Delay (2000);
			}
		}

		mainScene->init ();
		
		for (Manager *m : managers)
		{
			if (!m->init ()) return false; ;
		}

		inputSystem = dynamic_cast<InputSystem*>( SystemManager::GetInstance()->GetSystem (SystemType::INPUT));

		return initResult;
	}

	int Engine::run ()
	{
		// systemManager.Getsystem(inputsystem).quitrequested()
		while (!inputSystem->QuitResquested ())
		{
			// update
			update ();
			// render
			draw ();
		}

		return shutdown();
	}

	void Engine::update ()
	{
		//inputSystem.update ();
		for (Manager *m : managers)
		{
			m->update () ;
		}

		mainScene->update ();
	}

	void Engine::draw () const
	{
		mainScene->draw ();
		//Fill the surface white
		SDL_FillRect (screenSurface, NULL, SDL_MapRGB (screenSurface->format, 0xFF, 0xFF, 0xFF));
		SDL_BlitSurface(image, NULL, screenSurface, NULL);

	}

	int Engine::shutdown ()
	{
		if (!mainScene->shutdown ())
		{
			return 1;
		}

		for (Manager *m : managers)
		{
			m->shutdown ();
		}

		//Destroy window
		SDL_DestroyWindow (window);

		//Quit SDL subsystems
		SDL_Quit ();

		return 0;
	}
}