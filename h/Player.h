#pragma once
#include	"Character2.h"

class Player : public Character{
private:
	int m_mp;

	int m_criticalHitProbability;

	void Choice(Character*,InputManager*) override;

	double Attack(InputManager*) override;

	double Action(InputManager*) override;

	void Item(InputManager*) override;

	enum PLAYER_ATTACK { BLOW, FIRE, WATER, THUNDER }; //攻撃選択画面

	enum PLAYER_ACTION { RESEARCH, INSURT, BEG_LIFE, SUPRISE }; //行動選択画面

	enum PLAYER_ITEM { HERB, POTION, MARBLE_MEAT, SACREDTREE_FRUIT };//アイテム選択画面

public:
	Player();
	Player(const Player&,int = 1,int = 1,int = 1,int = 1);

	void ParamaterShow(InputManager* input) override;
};