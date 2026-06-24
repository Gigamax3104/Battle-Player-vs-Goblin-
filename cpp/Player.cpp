#include	"../h/Player.h"
#include	"../h/Variable.h"

#include	<iostream>

#include	<cstdlib>
#include	<ctime>
#include	<math.h>
#include	<conio.h>
using namespace std;

const char arrowDisplay[] = "->";
const size_t arrowLength = strlen(arrowDisplay);

const char* stateDisplay[] = { "ATTACK","ACTION","ITEM","GUARD",
							   "BLOW","WATER","FIRE","THUNDER",
							   "RESEARCH","INSURT","BEG_LIFE","SUPRISE",
							   "HERB","POTION","MARBLE_MEAT","SACREDTREE_FRUIT" };

static int stateDisplayIndex = 0;

void Set(InputManager* input) { //文字出力
	cout << arrowDisplay;

	for (int i = stateDisplayIndex * 4; i < (stateDisplayIndex + 1) * 4; i++) {
		cout << stateDisplay[i];

		if (i % 4 == 0) input->SetCursorPosition(Vector2(input->GetCursorPosition().x + (int)arrowLength, 2 * (i % 4 + 1)));
		else input->SetCursorPosition(Vector2(input->GetCursorPosition().x, 2 * (i % 4 + 1)));
	}

	input->SetCursorPosition(Vector2(input->GetCursorPosition().x - (int)arrowLength, 0));
}

void Clear(InputManager* input) { //文字削除
	for (int i = 0; i < 5; i++) {
		input->SetCursorPosition(Vector2(input->GetCursorPosition().x, 2 * i));
		input->ClearStringLate();
	}

	input->SetCursorPosition(Vector2(25, 0));
}

bool CursorMove(int* choice, InputManager* input) { //矢印キー入力
	if (_kbhit()) {
		int ch = _getch();

		if (ch == 'W' || ch == 'w' || ch == UP_KEY) { (*choice)--; if (*choice < 0) *choice = 3; }
		else if (ch == 'S' || ch == 's' || ch == DOWN_KEY) { (*choice)++; if (*choice > 3) *choice = 0; }
		else if (ch == ENTER_KEY) return false;

		cout << ' ' << ' ';

		input->SetCursorPosition(Vector2(input->GetCursorPosition().x, 2 * (*choice)));

		cout << arrowDisplay;

		input->SetCursorPosition(Vector2(input->GetCursorPosition().x, input->GetCursorPosition().y));
	}

	return true;
}

Player::Player() : Character(100, 10.0, 0.0, 0, 50, 4, "Hero", Vector2(0, 0)),m_mp(100),m_criticalHitProbability(10){}

Player::Player(const Player& other, int herbNumber, int potionNumber, int marble_meatNumber, int sacredTree_fruitNumber)
	: Character(other),m_mp(other.m_mp),m_criticalHitProbability(other.m_criticalHitProbability){
	m_item[HERB] = herbNumber;
	m_item[POTION] = potionNumber;
	m_item[MARBLE_MEAT] = marble_meatNumber;
	m_item[SACREDTREE_FRUIT] = sacredTree_fruitNumber;
}

void Player::ChoiceBase(Character* ch, InputManager* input) {
	int choice(ATTACK);

	input->SetCursorPosition(Vector2(25, 0));

	Set(input);

	while (CursorMove(&choice, input));

	stateDisplayIndex = choice + 1;

	if (choice == ATTACK) {
		if (!ch->Dodge()) ch->Damage((int)Attack(input));
	}
	else if (choice == ACTION) {
		double a(Action(input));

		if (a != -1.0) ch->ChangePower(a);
		else ch->Character::ParamaterShow(input);
	}
	else if (choice == ITEM) Item(input);
	else Guard();

	stateDisplayIndex = 0;

	Clear(input);
}

double Player::Attack(InputManager* input) {
	int choice(BLOW);

	Clear(input);

	Set(input);

	while (CursorMove(&choice, input));

	if (choice == BLOW) {
		int criticalChance(rand() % Probability);

		if (criticalChance <= m_criticalHitProbability) return m_power * 2;
		else return m_power;
	}
	else if (choice == FIRE) {
		if (m_mp <= 0) return 0;
		else { m_mp -= 3; return rand() % 6 + 5; }
	}
	else if (choice == WATER) {
		if (m_mp <= 0) return 0;
		else { m_mp -= 5; return rand() % 8 + 10; }
	}
	else if (choice == THUNDER) {
		if (m_mp <= 0) return 0;
		else { m_mp -= 8; return rand() % 11 + 20; }
	}

	return -1.0;
}

double Player::Action(InputManager* input) {
	int choice(RESEARCH);

	Clear(input);

	Set(input);

	while (CursorMove(&choice, input));

	return
		choice == RESEARCH ? -1.0 :
		choice == INSURT ? 2.0 :
		choice == BEG_LIFE ? 1.0 : 0.5;
}

void Player::Item(InputManager* input) {
	int choice(HERB);

	Clear(input);

	Set(input);

	while (CursorMove(&choice, input));

	if (choice == HERB) if (m_item[HERB] == 0) return; else { m_hp += 10; m_mp += 10; }
	else if (choice == POTION) if (m_item[POTION] == 0) return; else { m_mp += 20; }
	else if (choice == MARBLE_MEAT) if (m_item[MARBLE_MEAT] == 0) return; else { m_hp += 30; m_power += 10; }
	else { if (m_item[SACREDTREE_FRUIT] == 0) return; else { m_hp += 15; m_power += 30; m_dodgeProbability += 20; } }
}

void Player::ParamaterShow(InputManager* input) {
	input->SetCursorPosition(Vector2(0, 5));
	input->ClearStringLate();

	cout << "HP : " << m_hp << ' ' << "MP : " << m_mp;

	input->SetCursorPosition(Vector2(6, input->GetCursorPosition().y + 1));
	cout << m_name << endl;
}

//↓以前までのコード
//const int stateDisplay_Division = PlayerState::STATE::GUARD + 1;
//
//const int stateDisplay_Array_Length = sizeof stateDisplay / sizeof * stateDisplay + 1;
//static int* stateDisplay_Length = nullptr;

//Player::Player() : Character(100, 10, 0, 0, 50, "Hero", Vector2(0, 0)), m_mp(100),
//item(new int[CHOICE_ITEM::SACREDTREE_FRUIT + 1]), m_criticalHitProbability(30) {
//	item[CHOICE_ITEM::HERB] = 1;
//	item[CHOICE_ITEM::POTION] = 1;
//	item[CHOICE_ITEM::MARBLE_MEAT] = 1;
//	item[CHOICE_ITEM::SACREDTREE_FRUIT] = 1;
//
//	int code(0);
//
//	stateDisplay_Length = new int[stateDisplay_Array_Length];
//
//	for (int i = 0; i < stateDisplay_Array_Length - 1; i++) {
//		stateDisplay_Length[i] = 0;
//
//		code = 0;
//
//		while (stateDisplay[i][code] != '\0') {
//			stateDisplay_Length[i]++;
//			code++;
//		}
//
//		if (i == stateDisplay_Array_Length - 2) { stateDisplay_Length[i + 1] = 0;code = 0; }
//	}
//
//	while (arrowDisplay[code] != '\0') {
//		stateDisplay_Length[stateDisplay_Array_Length - 1]++;
//		code++;
//	}
//}
//
//Player::Player(const Player& other, int mp, int criticalProbability, int herbNumber, int potionNumber, int marble_meatNumber, int sacredTree_fruitNumber)
//	: Character(other), m_mp(mp), item(new int[CHOICE_ITEM::SACREDTREE_FRUIT + 1]), m_criticalHitProbability(criticalProbability) {
//	int code(0);
//
//	if (m_mp < 0) m_mp = 0;
//	if (m_criticalHitProbability < 0) m_criticalHitProbability = 0;
//
//	item[CHOICE_ITEM::HERB] = herbNumber; if (item[CHOICE_ITEM::HERB] < 0) item[CHOICE_ITEM::HERB] = 0;
//	item[CHOICE_ITEM::POTION] = potionNumber; if (item[CHOICE_ITEM::POTION] < 0) item[CHOICE_ITEM::POTION] = 0;
//	item[CHOICE_ITEM::MARBLE_MEAT] = marble_meatNumber; if (item[CHOICE_ITEM::MARBLE_MEAT] < 0) item[CHOICE_ITEM::MARBLE_MEAT] = 0;
//	item[CHOICE_ITEM::SACREDTREE_FRUIT] = sacredTree_fruitNumber; if (item[CHOICE_ITEM::SACREDTREE_FRUIT] < 0) item[CHOICE_ITEM::SACREDTREE_FRUIT] = 0;
//	if(stateDisplay_Length == nullptr) {
//		int count = sizeof stateDisplay / sizeof * stateDisplay + 1;
//		stateDisplay_Length = new int[count];
//
//		for (int i = 0; i < count - 1; i++) {
//			stateDisplay_Length[i] = 0;
//
//			code = 0;
//
//			while (stateDisplay[i][code] != '\0') {
//				stateDisplay_Length[i]++;
//				code++;
//			}
//
//			if (i == count - 2) { stateDisplay_Length[i + 1] = 0; code = 0; }
//		}
//
//		while (arrowDisplay[code] != '\0') {
//			stateDisplay_Length[count - 1]++;
//			code++;
//		}
//	}
//}
//
//PlayerState::STATE Player::Choice(InputManager* input) {
//	static int choice(STATE::ATTACK);
//
//	input->SetCursorPosition(Vector2(25, 0));
//
//	cout << arrowDisplay;
//
//	for (int i = 0; i < stateDisplay_Division; i++) {
//		cout << stateDisplay[i];
//
//		if(i == 0) input->SetCursorPosition(Vector2(input->GetCursorPosition().x + stateDisplay_Length[stateDisplay_Array_Length - 1], 2 * (i + 1)));
//		else input->SetCursorPosition(Vector2(input->GetCursorPosition().x, 2 * (i + 1)));
//	}
//
//	input->SetCursorPosition(Vector2(input->GetCursorPosition().x - 2, choice));
//
//	while (1) {
//		if (_kbhit()) {
//			int ch = _getch();
//
//			if (ch == 'W' || ch == 'w' || ch == UP_KEY) {
//				choice--;
//
//				if (choice < STATE::ATTACK) choice = STATE::GUARD;
//			}
//			else if (ch == 'S' || ch == 's' || ch == DOWN_KEY) {
//				choice++;
//
//				if (choice > STATE::GUARD) choice = STATE::ATTACK;
//			}
//			else if (ch == ENTER_KEY) return static_cast<STATE>(choice);
//
//			cout << ' ' << ' ';
//
//			input->SetCursorPosition(Vector2(input->GetCursorPosition().x, 2 * choice));
//
//			cout << arrowDisplay;
//
//			input->SetCursorPosition(Vector2(input->GetCursorPosition().x, input->GetCursorPosition().y));
//		}
//	}
//}
//
//PlayerState::CHOICE_ATTACK Player::Choice_Attack(InputManager* input) {
//	static int choice(CHOICE_ATTACK::BLOW);
//
//	if (_kbhit()) {
//		int ch = _getch();
//
//		if (ch == 'W' || ch == 'w' || ch == UP_KEY) {
//			choice--;
//
//			if (choice < CHOICE_ATTACK::BLOW) choice = CHOICE_ATTACK::THUNDER;
//		}
//		else if (ch == 'S' || ch == 's' || ch == DOWN_KEY) {
//			choice++;
//
//			if (choice > CHOICE_ATTACK::THUNDER) choice = CHOICE_ATTACK::BLOW;
//		}
//		else if (ch == ENTER_KEY) return static_cast<CHOICE_ATTACK>(choice);
//
//		cout << ' ' << ' ';
//
//		input->SetCursorPosition(Vector2(input->GetCursorPosition().x, 2 * choice));
//
//		cout << arrowDisplay;
//
//		input->SetCursorPosition(Vector2(input->GetCursorPosition().x, input->GetCursorPosition().y));
//	}
//
//	return CHOICE_ATTACK::ENDRESS_ATTACK;
//}
//
//int Player::Player_Attack(InputManager* input) {
//	int criticalChance(0);
//
//	CHOICE_ATTACK choice(CHOICE_ATTACK::BLOW);
//
//	//input->SetCursorPosition(Vector2(25, 0));
//
//	//cout << arrowDisplay;
//
//	//for (int i = stateDisplay_Division; i < (STATE::ATTACK + 2) * stateDisplay_Division; i++) {
//	//	cout << stateDisplay[i];
//
//	//	if (i == stateDisplay_Division - 1) input->SetCursorPosition(Vector2(input->GetCursorPosition().x + stateDisplay_Length[stateDisplay_Array_Length - 1], 2 * (i + 1)));
//	//	else input->SetCursorPosition(Vector2(input->GetCursorPosition().x, 2 * (i + 1)));
//	//}
//
//	//input->SetCursorPosition(Vector2(input->GetCursorPosition().x - 2, choice));
//
//	while (1) { if (choice != ENDRESS_ATTACK) break; choice = Choice_Attack(input); }
//
//	switch (choice) {
//	case BLOW:
//		criticalChance = rand() % Probability;
//
//		if (criticalChance <= m_criticalHitProbability) return m_power * 200;
//		else return m_power * 100;
//
//	case FIRE:
//		if (m_mp == 0) { cout << "NOTING MP!!" << endl; return 0; }
//
//		m_mp -= 3;
//		if (m_mp <= 0) { cout << "NOT ENOUGH MP!!" << endl; m_mp = 0; return 0; }
//
//		return rand() % 6 + 5;
//
//	case WATER:
//		if (m_mp == 0) { cout << "NOTING MP!!" << endl; return 0; }
//
//		m_mp -= 5;
//		if (m_mp <= 0) { cout << "NOT ENOUGH MP!!" << endl; m_mp = 0; return 0; }
//
//		return rand() % 8 + 10;
//
//		
//	case THUNDER:
//		if (m_mp == 0) { cout << "NOTING MP!!" << endl; return 0; }
//
//		m_mp -= 8;
//		if (m_mp <= 0) { cout << "NOT ENOUGH MP!!" << endl; m_mp = 0; return 0; }
//
//		return rand() % 11 + 20;
//	}
//}
//
//PlayerState::CHOICE_ACTION Player::Choice_Action(InputManager* input) {
//	static int choice(CHOICE_ACTION::RESEARCH);
//
//	if (_kbhit()) {
//		if (_getch() == 'W' || _getch() == 'w' || _getch() == UP_KEY) {
//			choice--;
//
//			if (choice < CHOICE_ACTION::RESEARCH) choice = CHOICE_ACTION::SUPRISE;
//		}
//		else if (_getch() == 'S' || _getch() == 's' || _getch() == DOWN_KEY) {
//			choice++;
//
//			if (choice > CHOICE_ACTION::SUPRISE) choice = CHOICE_ACTION::RESEARCH;
//		}
//		else if (_getch() == ENTER_KEY) return static_cast<CHOICE_ACTION>(choice);
//	}
//
//	return CHOICE_ACTION::ENDRESS_ACTION;
//}
//
//double Player::Player_Action(InputManager* input) {
//	CHOICE_ACTION choice(CHOICE_ACTION::ENDRESS_ACTION);
//
//	while (1) { choice = Choice_Action(input); if (choice != ENDRESS_ACTION) break; }
//
//	switch (choice) {
//	case RESEARCH:
//		return -1.0;
//
//	case INSURT:
//		return 2.0;
//
//	case BEG_LIFE:
//		return 0.0;
//
//	case SUPRISE:
//		return -1.5;
//	}
//}
//
//PlayerState::CHOICE_ITEM Player::Choice_Item(InputManager* input) {
//	static int choice(CHOICE_ITEM::HERB);
//
//	if (_kbhit()) {
//		if (_getch() == 'W' || _getch() == 'w' || _getch() == UP_KEY) {
//			choice--;
//
//			if (choice < CHOICE_ITEM::HERB) choice = CHOICE_ITEM::SACREDTREE_FRUIT;
//		}
//		else if (_getch() == 'S' || _getch() == 's' || _getch() == DOWN_KEY) {
//			choice++;
//
//			if (choice > CHOICE_ITEM::SACREDTREE_FRUIT) choice = CHOICE_ITEM::HERB;
//		}
//		else if (_getch() == ENTER_KEY) return static_cast<CHOICE_ITEM>(choice);
//	}
//
//	return CHOICE_ITEM::ENDRESS_ITEM;
//}
//
//void Player::Player_Item(InputManager* input) {
//	CHOICE_ITEM choice(CHOICE_ITEM::ENDRESS_ITEM);
//
//	while (1) { choice = Choice_Item(input); if (choice != ENDRESS_ITEM) break; }
//
//	switch (choice) {
//	case HERB:
//		if (item[CHOICE_ITEM::HERB] == 0) break;
//		else { m_hp += 10; m_mp += 10; break; }
//
//	case POTION:
//		if (item[CHOICE_ITEM::POTION] == 0) break;
//		else { m_mp += 20; break; }
//
//	case MARBLE_MEAT:
//		if (item[CHOICE_ITEM::MARBLE_MEAT] == 0) break;
//		else { m_hp += 30; m_power += 10; break; }
//
//	case SACREDTREE_FRUIT:
//		if (item[CHOICE_ITEM::SACREDTREE_FRUIT] == 0) break;
//		else { m_hp += 15; m_power += 30; m_dodgeProbability += 20; break; }
//	}
//}
//
//void Player::Guard() { m_difence *= 1.5; }
//
//bool Player::Dodge() { srand((unsigned int)time(NULL)); int dodgeChance = rand() % 100 + 1; return dodgeChance <= m_dodgeProbability; }
//
//void Player::Damage(int damage) { m_hp -= damage; if (m_hp < 0) m_hp = 0; }
//
//bool Player::IsArive() const { return m_hp <= 0; }
//
//
//void Player::DeleteString(InputManager* input,int stateNumber) {
//	input->SetCursorPosition(Vector2(input->GetCursorPosition().x + stateDisplay_Length[stateDisplay_Array_Length - 1], 0));
//
//	for (int i = stateNumber; i < stateNumber + stateDisplay_Division; i++) {
//		for (int j = 0; j < stateDisplay_Length[i]; j++) {
//			cout << " ";
//			input->SetCursorPosition(Vector2(input->GetCursorPosition().x + 1, input->GetCursorPosition().y));
//		}
//
//		if (stateNumber != 0) input->SetCursorPosition(Vector2(input->GetCursorPosition().x, 2 * (i % stateNumber)));
//		else input->SetCursorPosition(Vector2(input->GetCursorPosition().x, 2 * i));
//	}
//}