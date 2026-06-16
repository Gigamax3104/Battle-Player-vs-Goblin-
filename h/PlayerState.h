#pragma once
#include	"InputManager.h"

class PlayerState {
public:
	enum STATE { ATTACK, ACTION, ITEM, GUARD }; //選択画面

	enum CHOICE_ATTACK { BLOW, FIRE, WATER, THUNDER, ENDRESS_ATTACK }; //攻撃選択画面

	enum CHOICE_ACTION { RESEARCH, INSURT, BEG_LIFE, SUPRISE, ENDRESS_ACTION }; //行動選択画面

	enum CHOICE_ITEM { HERB, POTION, MARBLE_MEAT, SACREDTREE_FRUIT, ENDRESS_ITEM }; //アイテム選択画面

protected:
	virtual STATE Choice(InputManager* input) = 0; //選択

	virtual CHOICE_ATTACK Choice_Attack(InputManager* input) = 0; //攻撃選択

	virtual CHOICE_ACTION Choice_Action(InputManager* input) = 0; //行動選択

	virtual CHOICE_ITEM Choice_Item(InputManager* input) = 0; //アイテム選択
};