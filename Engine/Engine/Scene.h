#pragma once
#include <vector>

namespace core
{
	class Engine;
}

namespace scene
{
	class Scene
	{
	private:
		std::vector<class GameObject*> gameObjects;
	public:
		core::Engine* engine;

		Scene ();
		virtual ~Scene ();

		virtual bool init ();
		virtual void update ();
		virtual void draw () const;
		virtual bool shutdown ();
	};
}