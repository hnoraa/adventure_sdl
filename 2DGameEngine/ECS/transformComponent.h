#pragma once

#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include "components.h"

class TransformComponent : public Component {
public:
	TransformComponent() {
		_x = 0;
		_y = 0;
	}

	TransformComponent(int x, int y) {
		_x = x;
		_y = y;
	}

	void Init() override {
		_x = 0;
		_y = 0;
	}

	void Update() override {
		_x++;
		_y++;
	}

	int X() { return _x; }
	int Y() { return _y; }

	void SetPos(int x, int y) {
		_x = x;
		_y = y;
	}
private:
	int _x;
	int _y;
};

#endif // !TRANSFORM_COMPONENT_H
