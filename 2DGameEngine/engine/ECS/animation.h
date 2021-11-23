#pragma once

#ifndef ANIMATION_H
#define ANIMATION_H

#include "../global/defines.h"
#include "components.h"

struct Animation
{
	int index;		// offset of the spritesheet
	int frames;		// number of frames for this animation
	int speed;		// delay
	int xOffset;	// where the animation starts

	Animation() {}

	Animation(int mIndex, int mFrames, int mSpeed, int mXOffset)
	{
		index = mIndex;
		frames = mFrames;
		speed = mSpeed;
		xOffset = mXOffset;
	}
};

#endif // !ANIMATION_H
