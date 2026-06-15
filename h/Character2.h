#pragma once

#include	"CharacterBase.h"
#include	"Vector2.h"
#include	"InputManager.h"

#include	<cstring>

class Character {
private:
	int m_save_hp = 0 ;
	double m_save_power = 0.0;
	double m_save_difence = 0;
	int m_save_mitigation = 0;

	int m_save_dodgeProbability = 0;

protected:
	int m_hp;
	double m_power;
	int m_difence;
	int m_mitigation;

	const int Probability = 100 + 1;
	int m_dodgeProbability;

	char* m_name;

	Position m_pos;

public:
	Character();

	Character(int hp, double power, double difence, int mitigation, int doddgeProbability, const char* name, const Vector2& pos);

	Character(const Character& character);

	virtual ~Character();

	void operator=(const Character& character);

	virtual void Move(const Vector2& position) { m_pos.AddPosition(position); }

	virtual void ParamaterShow(InputManager* input);

	int GetNameLength() const { return strlen(m_name) + 1; }

	void ResetPower() { m_power = m_save_power; }

	void ResetDifence() { m_difence = m_save_difence; }

	void ResetMitigation() { m_mitigation = m_save_mitigation; }

	void ResetDodgeProbability() { m_dodgeProbability = m_save_dodgeProbability; }

	void Reset() { ResetPower(); ResetDifence(); ResetMitigation(); ResetDodgeProbability(); }
};