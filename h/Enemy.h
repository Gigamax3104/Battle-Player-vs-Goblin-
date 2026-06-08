#pragma once
#include	"Characterr.h"

class Enemy : public Character {
public:
	Enemy() : Character(50, 10, 0, 0, 10, "Goblin") {}
	Enemy(const Enemy& other) : Character(other) {}
};