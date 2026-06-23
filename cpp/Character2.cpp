#include	"../h/Character2.h"

#include	<ctime>
#include	<cstdlib>
#include	<iostream>
using namespace std;

// デフォルトコンストラクタ
Character::Character()
	: m_save_hp(0), m_save_power(0.0), m_save_difence(0.0), m_save_mitigation(0)
	, m_save_dodgeProbability(0), m_hp(0), m_power(0.0), m_difence(0.0)
	, m_mitigation(0), m_dodgeProbability(0), m_item(nullptr), m_itemNumber(0)
	, m_name(nullptr), m_pos(){}

// 引数つきコンストラクタ
Character::Character(int hp, double power, double difence, int mitigation, int dodgeProb, int itemNumber, const char* name, const Vector2& pos)
	: m_save_hp(hp), m_save_power(power), m_save_difence(difence)
	, m_save_mitigation(mitigation), m_save_dodgeProbability(dodgeProb)
	, m_hp(hp), m_power(power), m_difence(difence), m_mitigation(mitigation)
	, m_dodgeProbability(dodgeProb), m_item(nullptr), m_itemNumber(itemNumber)
	, m_name(nullptr), m_pos(pos)
{
	if (name) m_name = _strdup(name); // strdup 等で名前を複製

	if (itemNumber > 0) m_item = new int[itemNumber]();
}

// コピーコンストラクタ
Character::Character(const Character& other)
	: m_save_hp(other.m_save_hp), m_save_power(other.m_save_power)
	, m_save_difence(other.m_save_difence)
	, m_save_mitigation(other.m_save_mitigation)
	, m_save_dodgeProbability(other.m_save_dodgeProbability)
	, m_hp(other.m_hp), m_power(other.m_power), m_difence(other.m_difence)
	, m_mitigation(other.m_mitigation)
	, m_dodgeProbability(other.m_dodgeProbability), m_item(nullptr)
	, m_itemNumber(other.m_itemNumber), m_name(nullptr), m_pos(other.m_pos)
{
	if (other.m_name) m_name = _strdup(other.m_name);

	if (other.m_itemNumber > 0 && other.m_item) {
		m_item = new int[other.m_itemNumber];
		memcpy(m_item, other.m_item, sizeof(int) * other.m_itemNumber);
	}
}

Character::~Character() {
	if (m_name != nullptr) {
		if (*m_name == '\0' || *m_name == NULL) delete m_name;
		else delete[] m_name;

		m_name = nullptr;
	}
}

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

void Character::Choice(Character* ch,InputManager* input) {
	srand((unsigned int)time(NULL));

	int r = rand() % 4;

	if (r == ATTACK) if (!ch->Dodge()) ch->Damage(Attack());
	else if (r == ACTION) ch->ChangePower(Action());
	else if (r == ITEM) Item();
	else Guard();
}

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

void Character::ParamaterShow(InputManager* input) {
	input->SetCursorPosition(Vector2(30, 0));

	cout << "Name : " << m_name << endl
		<< "HP : " << m_hp << endl
		<< "Attack : " << m_power << endl
		<< "Difence : " << m_difence << endl
		<< "Mitigation : " << m_mitigation << "%" << endl
		<< "Dodge :" << m_dodgeProbability << "%" << endl;

	input->SetCursorPosition(Vector2(27, 0));
}