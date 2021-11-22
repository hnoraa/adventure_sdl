#pragma once

#ifndef KEYBOARD_CONTROLLER_H
#define KEYBOARD_CONTROLLER_H

#include "../game.h"
#include "components.h"

class KeyboardController : public Component
{
public:
	TransformComponent* transform;

	void Init() override
	{
		// get the transform component of the parent entity
		transform = &entity->GetComponent<TransformComponent>();
	}

	void Update() override
	{
		// get key presses
		if (Game::evt.type == SDL_KEYDOWN)
		{
			// start key press operation
			switch (Game::evt.key.keysym.sym)
			{
			case SDLK_UP:
				transform->velocity.y = -1;	// moving up
				break;
			case SDLK_DOWN:
				transform->velocity.y = 1;	// moving down
				break;
			case SDLK_LEFT:
				transform->velocity.x = -1;	// moving left
				break;
			case SDLK_RIGHT:
				transform->velocity.x = 1;	// moving right
				break;
			default:
				break;
			}
		}

		if (Game::evt.type == SDL_KEYUP)
		{
			// stop key press operation (ex. stop moving)
			switch (Game::evt.key.keysym.sym)
			{
			case SDLK_UP:
				transform->velocity.y = 0;	// moving up
				break;
			case SDLK_DOWN:
				transform->velocity.y = 0;	// moving down
				break;
			case SDLK_LEFT:
				transform->velocity.x = 0;	// moving left
				break;
			case SDLK_RIGHT:
				transform->velocity.x = 0;	// moving right
				break;
			default:
				break;
			}
		}
	}
};

#endif // !KEYBOARD_CONTROLLER_H