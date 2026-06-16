#pragma once
#include	"Character2.h"

class Enemy : public Character,CharacterBase {
private:
	int m_item; //アイテム

public:
	Enemy() : Character(50, 10, 0, 0, 10, "Goblin",Vector2(0,0)),m_item(1) {}
	Enemy(const Enemy& other) : Character(other),m_item(other.m_item) {}

	int Attack() override;

	double Action() override;

	void Item() override;

	void Guard() override;

	bool Dodge() override;

	void Damage(int damage) override;

	bool IsArive() const override;

	void ParamaterShow(InputManager* input) override;
};