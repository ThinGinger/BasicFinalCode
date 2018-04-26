#pragma once
#ifndef _ENGINE_H
#define _ENGINE_H
#include <SDL.h>

#include <vector>
#include "InputSystem.h"
#include "SystemManager.h"

#define ENGINE_INIT_ERROR		1
#define ENGINE_SHUTDOWN_ERROR	2

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 960;

namespace scene
{
	class Scene;
}

namespace core
{
	class Engine
	{
	private:
		bool isRunning;
		std::vector<Manager*> managers;

		scene::Scene* mainScene;

		// TODO: move these to the window system
		//The window we'll be rendering to
		SDL_Window* window = NULL;
		//The surface contained by the window
		SDL_Surface* screenSurface = NULL;

		core::InputSystem* inputSystem;

	public:
		Engine (scene::Scene *s);
		~Engine ();

		int init ();
		int run ();

		void stopRunning () { isRunning = false; }

		SDL_Surface* getSurface () { return screenSurface; }
		SDL_Window* getWindow () { return window; }

	private:
		void update ();
		void draw () const;
		int shutdown ();
	};
}

#endif