#pragma once
#include	"Character2.h"

class Enemy : public Character {
private:
	void ChoiceBase(Character*, InputManager* = nullptr);
	double Attack(InputManager* = nullptr) override { return m_power; }
	double Action(InputManager* = nullptr) override { return -1.0; }
	void Item(InputManager* = nullptr) override;

public:
	Enemy() : Character(50, 10.0, 0.0, 0, 10, 1, "Goblin",Vector2(0,0)) {}
	Enemy(const Enemy& other) : Character(other) {}

	void ParamaterShow(InputManager* input) override;
};