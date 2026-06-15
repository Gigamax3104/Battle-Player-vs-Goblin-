#include	"../h/Character2.h"
#include	<cstring>
#include	<iostream>
using namespace std;

Character::Character() : m_hp(0), m_power(0.0), m_difence(0.0), m_mitigation(0), m_dodgeProbability(0),m_name(new char[1]), m_pos(Vector2(0, 0)) {
	*m_name = '\0';
}

Character::Character(int hp, double power, double difence, int mitigation,
	int doddgeProbability, const char* name, const Vector2& pos) :
	m_hp(hp), m_power(power), m_difence(difence), m_mitigation(mitigation), m_dodgeProbability(doddgeProbability), m_pos(pos)
{
	if (m_hp < 0) m_hp = 0;
	m_save_hp = m_hp;

	if (m_power < 0.0) m_power = 0.0;
	m_save_power = m_power;

	if (m_difence < 0.0) m_difence = 0.0;
	m_save_difence = m_difence;

	if (m_mitigation < 0) m_mitigation = 0;
	m_save_mitigation = m_mitigation;

	if (m_dodgeProbability < 0) m_dodgeProbability = 0;
	m_save_dodgeProbability = m_dodgeProbability;

	if (name == nullptr) m_name = nullptr;
	else {
		m_name = new char[strlen(name) + 1];

		strcpy_s(m_name, strlen(name) + 1, name);
	}
}

Character::Character(const Character& character) :
	m_hp(character.m_hp), m_power(character.m_power), m_difence(character.m_difence), m_mitigation(character.m_mitigation),
	m_dodgeProbability(character.m_dodgeProbability), m_pos(character.m_pos)
{
	if (this->m_hp < 0) this->m_hp = 0;
	this->m_save_hp = this->m_hp;

	if (this->m_power < 0.0) this->m_power = 0.0;
	this->m_save_power = this->m_power;

	if (this->m_difence < 0.0) this->m_difence = 0.0;
	this->m_save_difence = this->m_difence;

	if (this->m_mitigation < 0) this->m_mitigation = 0;
	this->m_save_mitigation = this->m_mitigation;

	if (this->m_dodgeProbability < 0) this->m_dodgeProbability = 0;
	this->m_save_dodgeProbability = this->m_dodgeProbability;

	if (character.m_name == nullptr) this->m_name = nullptr;
	else {
		this->m_name = new char[character.GetNameLength()];

		strcpy_s(this->m_name, character.GetNameLength(), character.m_name);
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
	if (this != &character) return;

	if (this->m_name != nullptr) {
		delete[] this->m_name;
		this->m_name = nullptr;
	}

	this->m_hp = character.m_hp;
	this->m_power = character.m_power;
	this->m_difence = character.m_difence;
	this->m_mitigation = character.m_mitigation;
	this->m_dodgeProbability = character.m_dodgeProbability;

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

	this->m_name = new char[character.GetNameLength()];
	strcpy_s(this->m_name, character.GetNameLength(), character.m_name);
}

void Character::ParamaterShow(InputManager* input) {
	cout << "Name : " << m_name << endl
		<< "HP : " << m_hp << endl
		<< "Attack : " << m_power << endl
		<< "Difence : " << m_difence << endl
		<< "Mitigation : " << m_mitigation << "%" << endl
		<< "Dodge :" << m_dodgeProbability << "%" << endl;
}