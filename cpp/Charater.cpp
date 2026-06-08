#include	"../h/Characterr.h"
#include	<iostream>
using namespace std;

void Character::Show() const {
	cout << "Name: " << m_name << endl;
	cout << "Health: " << m_hp << endl;
	cout << "Attack: " << m_attackPower << endl;
	cout << "Defense: " << m_defensePower << endl;
	cout << "Mitigation: " << m_mitigation << "%" << endl;
	cout << "Dodge: " << m_dodge << "%" << endl;
}

bool Character::attack(Character& target) {
	if (!isAlive()) {
		cout << m_name << " cannot attack because they are defeated." << endl;
		return false;
	}

	if (!target.isAlive()) {
		cout << target.m_name << " is already defeated." << endl;
		return false;
	}

	double dodgeChance = (rand() % 100) + 1; // 1から100の乱数

	if (dodgeChance <= target.m_dodge) {
		cout << target.m_name << " dodged the attack!" << endl;
		return true;
	}

	int damage = m_attackPower - target.m_defensePower;
	damage -= damage * (target.m_mitigation / 100.0); // ダメージ軽減を適用
	if (damage < 0) damage = 0; // ダメージがマイナスにならないようにする

	target.m_hp -= damage;

	cout << m_name << " attacks " << target.m_name << " for " << damage << " damage!" << endl;
	if (!target.isAlive()) {
		cout << target.m_name << " has been defeated!" << endl;
	}

	return true;
}