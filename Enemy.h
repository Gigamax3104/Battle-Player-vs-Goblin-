#pragma once
#include	"Character.h"

class Enemy : public Character {
public:
	Enemy() : Character(50, 10, 5, 0, 10, "Goblin") {}
};