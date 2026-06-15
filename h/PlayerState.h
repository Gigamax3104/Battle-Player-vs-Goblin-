#pragma once
#include	"InputManager.h"

class PlayerState {
public:
	enum STATE { ATTACK, ACTION, ITEM, GUARD };

	enum CHOICE_ATTACK { BLOW, FIRE, WATER, THUNDER, ENDRESS_ATTACK };

	enum CHOICE_ACTION { RESEARCH, INSURT, BEG_LIFE, SUPRISE, ENDRESS_ACTION };

	enum CHOICE_ITEM { HERB, POTION, MARBLE_MEAT, SACREDTREE_FRUIT, ENDRESS_ITEM };

protected:
	virtual STATE Choice(InputManager* input) = 0;

	virtual CHOICE_ATTACK Choice_Attack(InputManager* input) = 0;

	virtual CHOICE_ACTION Choice_Action(InputManager* input) = 0;

	virtual CHOICE_ITEM Choice_Item(InputManager* input) = 0;
};