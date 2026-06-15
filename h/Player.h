#pragma once
#include	"Character2.h"
#include	"PlayerState.h"

class Player : public Character, CharacterBase,PlayerState {
private:
	int m_mp;

	int m_criticalHitProbability;

	int* item;

public:
	Player();
	Player(const Player& other, int mp, int criticalProbability,int herbNumber = 1,int potionNumber = 1,int marble_meatNumber = 1,int sacredTree_fruitNumber = 1);

	STATE Choice(InputManager* input) override;

	int Attack() override { return -1; }
	int Player_Attack(InputManager* input);
	CHOICE_ATTACK Choice_Attack(InputManager* input) override;

	double Action() override { return -1.0; }
	double Player_Action(InputManager* input);
	CHOICE_ACTION Choice_Action(InputManager* input) override;

	void Item() override {}
	void Player_Item(InputManager* input);
	CHOICE_ITEM Choice_Item(InputManager* input) override;

	void Guard() override;

	bool Dodge() override;

	void Damage(int damage) override;

	bool IsArive() const override;

	void ParamaterShow(InputManager* input) override;

	void DeleteString(InputManager* input,int stateNumber = 0);
};