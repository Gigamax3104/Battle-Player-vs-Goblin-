#pragma once

#include	"Vector2.h"
#include	"InputManager.h"

#include	<cstring>

class Character{
private:
	int m_save_hp = 0 ; //HP保存変数
	double m_save_power = 0.0; //ATK保存変数
	double m_save_difence = 0; //DEF保存変数
	int m_save_mitigation = 0; //軽減率保存変数

	int m_save_dodgeProbability = 0; //回避率保存変数

	void ResetPower() { m_power = m_save_power; } //ATKリセット

	void ResetDifence() { m_difence = m_save_difence; } //DEFリセット

	void ResetMitigation() { m_mitigation = m_save_mitigation; } //軽減率リセット

	void ResetDodgeProbability() { m_dodgeProbability = m_save_dodgeProbability; } //回避率リセット

protected:
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

	enum STATE { ATTACK, ACTION, ITEM, GUARD };

	virtual double Attack(InputManager* = nullptr) { return m_power; }

	virtual double Action(InputManager* = nullptr) { return 1.0; }

	virtual void Item(InputManager* = nullptr);

	void Guard() { m_difence *= 1.5; }

public:
	Character(); //コンストラクタ

	Character(int, double, double, int, int, int, const char*, const Vector2&);
	//引数つきコンストラクタ

	Character(const Character&);
	//引数つきコンストラクタ(Character版)

	virtual ~Character(); //デストラクタ(仮想デストラクタ)

	void operator=(const Character&); //代入演算子オーバーロード

	virtual void Choice(Character*,InputManager* = nullptr);

	bool Dodge() const { srand(time(NULL)); return rand() % 100 + 1 <= m_dodgeProbability; }

	void Damage(int damage) { m_hp -= damage; if (m_hp < 0) m_hp = 0; }

	void ChangePower(double down) { m_power *= down; }

	bool IsArive() const { return m_hp > 0; }

	virtual void Move(const Vector2& position) { m_pos.AddPosition(position); } //移動

	virtual void ParamaterShow(InputManager*); //パラメーター表示

	size_t GetNameLength() const { return strlen(m_name) + 1; } //名前の長さ取得

	void Reset() { ResetPower(); ResetDifence(); ResetMitigation(); ResetDodgeProbability(); } //それら全てリセット
};