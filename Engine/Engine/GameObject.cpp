#include "GameObject.h"
#include <string>
namespace scene
{
	GameObject::GameObject (std::string filePath)
	{
		objectImage = SDL_LoadBMP (filePath.c_str());

		if (objectImage == NULL)
		{
			printf ("Unable to load image %s! SDL Error: %s\n", filePath.c_str (), SDL_GetError ());
		}
	}


	GameObject::~GameObject ()
	{
	}

	bool GameObject::init ()
	{
		return true;
	}
	void GameObject::update ()
	{

	}
	void GameObject::draw () const
	{

	}
	bool GameObject::shutdown ()
	{
		return true;
	}
}

