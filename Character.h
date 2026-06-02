#pragma once

class Character {
protected:
	int m_hp; //体力
	int m_attackPower; //攻撃力
	int m_defensePower; //防御力
	int m_mitigation; //ダメージ軽減率

	double m_dodge; //回避率

	const char* m_name; //名前

public:
	Character(int hp, int attack, int defense, int mitigation, double dodge, const char* name)
		: m_hp(hp), m_attackPower(attack), m_defensePower(defense), m_mitigation(mitigation), m_dodge(dodge), m_name(new char[strlen(name) + 1]) {
		strcpy(m_name, name);
	}

	Character(const Character& other)
		: m_hp(other.m_hp), m_attackPower(other.m_attackPower), m_defensePower(other.m_defensePower),
		m_mitigation(other.m_mitigation), m_dodge(other.m_dodge), m_name(new char[strlen(other.m_name) + 1]) {
		strcpy(m_name, other.m_name);
	}

	void Show() const;

	void attack(Character& target);

	bool isAlive() const { return hp > 0; }
};