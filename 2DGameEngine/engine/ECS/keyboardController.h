#pragma once

#ifndef KEYBOARD_CONTROLLER_H
#define KEYBOARD_CONTROLLER_H

#include "../game.h"
#include "components.h"

class KeyboardController : public Component
{
public:
	TransformComponent* transform;
	SpriteComponent* sprite;

	void Init() override
	{
		// get the transform component of the parent entity
		transform = &entity->GetComponent<TransformComponent>();
		sprite = &entity->GetComponent<SpriteComponent>();
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
				sprite->Play("walk");
				break;
			case SDLK_DOWN:
				transform->velocity.y = 1;	// moving down
				sprite->Play("walk");
				break;
			case SDLK_LEFT:
				transform->velocity.x = -1;	// moving left
				sprite->Play("walk");
				sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
				break;
			case SDLK_RIGHT:
				transform->velocity.x = 1;	// moving right
				sprite->Play("walk");
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
				sprite->Play("idleBack");
				break;
			case SDLK_DOWN:
				transform->velocity.y = 0;	// moving down
				sprite->Play("idleFront");
				break;
			case SDLK_LEFT:
				transform->velocity.x = 0;	// moving left
				sprite->Play("idleFront");
				sprite->spriteFlip = SDL_FLIP_NONE;

				break;
			case SDLK_RIGHT:
				transform->velocity.x = 0;	// moving right
				sprite->Play("idleFront");
				break;
			case SDLK_ESCAPE:
				// quit
				if (DEBUG)
				{
					Game::isRunning = false;
				}
			default:
				break;
			}
		}
	}
};

#endif // !KEYBOARD_CONTROLLER_H
