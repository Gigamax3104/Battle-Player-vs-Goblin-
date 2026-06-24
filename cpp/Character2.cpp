#include	"../h/Character2.h"

#include	<ctime>
#include	<cstdlib>
#include	<iostream>
using namespace std;

// 引数つきコンストラクタ
Character::Character(int hp, double power, double difence, int mitigation, int dodgeProb, int itemNumber, const char* name, const Vector2& pos)
	: CharacterBase(hp,power,difence,mitigation,dodgeProb,itemNumber,name,pos){}

void Character::operator=(const Character& character) {
	if (this == &character) return;

	if (this->m_name != nullptr) {
		delete[] this->m_name;
		this->m_name = nullptr;
	}
	
	if (this->m_item != nullptr) {
		delete[] this->m_item;
		this->m_item = nullptr;
	}

	this->m_hp = character.m_hp;
	this->m_save_hp = this->m_hp;

	this->m_power = character.m_power;
	this->m_save_power = this->m_power;

	this->m_difence = character.m_difence;
	this->m_save_difence = this->m_difence;

	this->m_mitigation = character.m_mitigation;
	this->m_save_mitigation = this->m_mitigation;

	this->m_dodgeProbability = character.m_dodgeProbability;
	this->m_save_dodgeProbability = this->m_dodgeProbability;

	if (this->m_hp < 0) this->m_hp = 0;
	this->m_save_hp = this->m_hp;

	if (this->m_power < 0) this->m_power = 0;
	this->m_save_power = this->m_power;

	if (this->m_difence < 0) this->m_difence = 0;
	this->m_save_difence = this->m_difence;

	if (this->m_mitigation < 0) this->m_mitigation = 0;
	this->m_save_mitigation = this->m_mitigation;

	if (this->m_dodgeProbability < 0) this->m_dodgeProbability = 0;
	this->m_save_dodgeProbability = this->m_dodgeProbability;

	// 名前のコピー（nullptr に対応）
	if (character.m_name == nullptr) {
		this->m_name = nullptr;
	} else {
		size_t len = character.GetNameLength(); // strlen + 1
		this->m_name = new char[len];
		strcpy_s(this->m_name, len, character.m_name);
	}

	// アイテム配列のコピー（要素数が正の場合のみ確保）
	if (character.m_itemNumber > 0) {
		if (character.m_itemNumber > 4) this->m_itemNumber = 4;
		else this->m_itemNumber = character.m_itemNumber;
		this->m_item = new int[this->m_itemNumber];

		for (int i = 0; i < this->m_itemNumber; i++) this->m_item[i] = character.m_item[i];
	} else {
		this->m_itemNumber = 0;
		this->m_item = nullptr;
	}
}

void Character::Choice(Character* ch, InputManager* input) { ChoiceBase(ch, input); }

void Character::Item(InputManager* input) {
	int r(rand() % 4);

	if (r > m_itemNumber) return;

	switch (r) {
	case 0:
		m_hp += 10;
		break;
		
	case 1:
		m_hp += 5; m_power += 5;
		break;

	case 2:
		m_hp += 5; m_difence += 5;
		break;

	case 3:
		m_hp += 10; m_mitigation += 5;
	}
}