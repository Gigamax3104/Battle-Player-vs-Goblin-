#pragma once
#include	"Character2.h"

class Enemy : public Character {
private:
	void Item(InputManager* = nullptr) override;

public:
	Enemy() : Character(50, 10.0, 0.0, 0, 10, 1, "Goblin",Vector2(0,0)) {}
	Enemy(const Enemy& other) : Character(other) {}

	void ParamaterShow(InputManager* input) override;
};