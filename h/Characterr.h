#pragma once
#include <cstring>

class Character {
protected:
	int m_hp; //体力
	int m_attackPower; //攻撃力
	int m_defensePower; //防御力
	int m_mitigation; //ダメージ軽減率

	double m_dodge; //回避率

	char* m_name; //名前（書き込み可能に修正）

public:
	// 既定コンストラクタを追加（配列 new に対応）
	Character()
		: m_hp(0), m_attackPower(0), m_defensePower(0), m_mitigation(0), m_dodge(0.0), m_name(new char[1]) {
		m_name[0] = '\0';
	}

	Character(int hp, int attack, int defense, int mitigation, double dodge, const char* name)
		: m_hp(hp), m_attackPower(attack), m_defensePower(defense), m_mitigation(mitigation), m_dodge(dodge), m_name(new char[std::strlen(name) + 1]) {
		strcpy_s(m_name, std::strlen(name) + 1, name);
	}

	Character(const Character& other)
		: m_hp(other.m_hp), m_attackPower(other.m_attackPower), m_defensePower(other.m_defensePower),
		m_mitigation(other.m_mitigation), m_dodge(other.m_dodge), m_name(new char[std::strlen(other.m_name) + 1]) {
		strcpy_s(m_name, std::strlen(other.m_name) + 1, other.m_name);
	}

	~Character() { delete[] m_name; }

	void Show() const;

	bool attack(Character& target);

	bool isAlive() const { return m_hp > 0; }
};