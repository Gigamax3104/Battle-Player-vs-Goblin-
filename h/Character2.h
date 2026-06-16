#pragma once

#include	"CharacterBase.h"
#include	"Vector2.h"
#include	"InputManager.h"

#include	<cstring>

class Character {
private:
	int m_save_hp = 0 ; //HP保存変数
	double m_save_power = 0.0; //ATK保存変数
	double m_save_difence = 0; //DEF保存変数
	int m_save_mitigation = 0; //軽減率保存変数

	int m_save_dodgeProbability = 0; //回避率保存変数

protected:
	int m_hp; //HP
	double m_power; //ATK
	int m_difence; //DEF
	int m_mitigation; //軽減率

	const int Probability = 100 + 1; //確率(100%固定)
	int m_dodgeProbability; //回避率

	char* m_name; //名前

	Position m_pos; //位置

public:
	Character(); //コンストラクタ

	Character(int hp, double power, double difence, int mitigation, int doddgeProbability, const char* name, const Vector2& pos);
	//引数つきコンストラクタ

	Character(const Character& character);
	//引数つきコンストラクタ(Character版)

	virtual ~Character(); //デストラクタ(仮想デストラクタ)

	void operator=(const Character& character); //代入演算子オーバーロード

	virtual void Move(const Vector2& position) { m_pos.AddPosition(position); } //移動

	virtual void ParamaterShow(InputManager* input); //パラメーター表示

	int GetNameLength() const { return strlen(m_name) + 1; } //名前の長さ取得

	void ResetPower() { m_power = m_save_power; } //ATKリセット

	void ResetDifence() { m_difence = m_save_difence; } //DEFリセット

	void ResetMitigation() { m_mitigation = m_save_mitigation; } //軽減率リセット

	void ResetDodgeProbability() { m_dodgeProbability = m_save_dodgeProbability; } //回避率リセット

	void Reset() { ResetPower(); ResetDifence(); ResetMitigation(); ResetDodgeProbability(); } //それら全てリセット
};