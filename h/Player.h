#pragma once
#include	"Characterr.h"

class Player : public Character {
public:
	Player() : Character(100, 10, 0, 0, 50, "Player") {}
	Player(const Player& other) : Character(other) {}
};