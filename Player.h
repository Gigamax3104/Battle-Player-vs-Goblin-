#pragma once
#include	"Character.h"

class Player : public Character {
public:
	Player() : Character(100, 10, 10, 0, 50, "Player") {}
};