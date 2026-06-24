#pragma once

#include	"CharacterBase.h"
#include	"InputManager.h"

#include	<cstring>

class Character : public CharacterBase{
public:
	Character() : CharacterBase(){}
	Character(int, double, double, int, int, int, const char*, const Vector2&);
	Character(const Character& other) : CharacterBase(other){}

	void operator=(const Character&);

	void Choice(Character*, InputManager* = nullptr);

	bool Dodge() const { srand((unsigned int)time(NULL)); return rand() % 100 + 1 <= m_dodgeProbability; }

	void Damage(int damage) { m_hp -= damage; if (m_hp < 0) m_hp = 0; }

	void ChangePower(double down) { m_power *= down; }

	bool IsArive() const { return m_hp > 0; }

protected:
	enum STATE { ATTACK, ACTION, ITEM, GUARD };

	virtual void ChoiceBase(Character*, InputManager* = nullptr) = 0;

	virtual double Attack(InputManager* = nullptr) = 0;

	virtual double Action(InputManager* = nullptr) = 0;

	virtual void Item(InputManager* = nullptr);

	void Guard() { m_difence *= 1.5; }

	virtual void Move(const Vector2& position) { m_pos.AddPosition(position); } //移動
};