#include	"Character.h"
#include	<iostream>
using namespace std;

void Character::Show() const {
	cout << "Name: " << name << endl;
	cout << "Health: " << hp << endl;
	cout << "Attack: " << attackPower << endl;
	cout << "Defense: " << defensePower << endl;
	cout << "Mitigation: " << mitigation << "%" << endl;
	cout << "Dodge: " << dodge << "%" << endl;
}

void Character::attack(Character& target) {
	if (!isAlive()) {
		cout << name << " cannot attack because they are defeated." << endl;
		return;
	}

	if (!target.isAlive()) {
		cout << target.name << " is already defeated." << endl;
		return;
	}

	double dodgeChance = (rand() % 100) + 1; // 1から100の乱数

	if (dodgeChance <= target.dodge) {
		cout << target.name << " dodged the attack!" << endl;
		return;
	}

	int damage = attackPower - target.defensePower;
	damage -= damage * (target.mitigation / 100.0); // ダメージ軽減を適用

	if (damage < 0) damage = 0; // ダメージがマイナスにならないようにする

	target.hp -= damage;

	cout << name << " attacks " << target.name << " for " << damage << " damage!" << endl;
	if (!target.isAlive()) {
		cout << target.name << " has been defeated!" << endl;
	}
}