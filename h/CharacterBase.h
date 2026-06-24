#pragma once
#include	"InputManager.h"
#include	<cstring>

class CharacterBase {
protected:
	CharacterBase();
	CharacterBase(int, double, double, int, int, int, const char*, const Vector2&);
	CharacterBase(const CharacterBase&);
	~CharacterBase();

	int m_save_hp = 0; //HP保存変数
	double m_save_power = 0.0; //ATK保存変数
	double m_save_difence = 0; //DEF保存変数
	int m_save_mitigation = 0; //軽減率保存変数

	int m_save_dodgeProbability = 0; //回避率保存変数

	void ResetPower() { m_power = m_save_power; } //ATKリセット

	void ResetDifence() { m_difence = m_save_difence; } //DEFリセット

	void ResetMitigation() { m_mitigation = m_save_mitigation; } //軽減率リセット

	void ResetDodgeProbability() { m_dodgeProbability = m_save_dodgeProbability; } //回避率リセット

	int m_hp; //HP
	double m_power; //ATK
	double m_difence; //DEF
	int m_mitigation; //軽減率

	const int Probability = 100 + 1; //確率(100%固定)
	int m_dodgeProbability; //回避率

	int* m_item; //アイテム
	int m_itemNumber;

	char* m_name; //名前

	Position m_pos; //位置

public:
	virtual void ParamaterShow(InputManager*); //パラメーター表示

	size_t GetNameLength() const { return strlen(m_name) + 1; } //名前の長さ取得

	void Reset() { ResetPower(); ResetDifence(); ResetMitigation(); ResetDodgeProbability(); } //それら全てリセット
};