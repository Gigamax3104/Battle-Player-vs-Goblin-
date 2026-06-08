#pragma once
#include <cstring>
#include <sstream>

class Character {
private:
	const char** show = nullptr;

	std::stringstream* ss = nullptr;

	enum STRINGSTREAM { NAME, HEALTH, ATTACK, DEFENSE, MITIGATION, DODGE }; //stringstreamで作成した文字列管理

	void Delete() {
		if (m_name != nullptr) {
			delete[] m_name; // 名前のメモリを解放
			m_name = nullptr; // ポインタをnullptrに設定
		}
	} // メモリ解放

	void New(const char* name) {
		Delete(); // 既存の名前のメモリを解放
		m_name = new char[strlen(name) + 1]; // 新しい名前のメモリを確保
		strcpy_s((char*)m_name, strlen(name) + 1, name); // 新しい名前をコピー
	} // 名前の更新

protected:
	int m_hp; //体力
	int m_attackPower; //攻撃力
	int m_defensePower; //防御力
	int m_mitigation; //ダメージ軽減率

	double m_dodge; //回避率

	const char* m_name; //名前

public:
    Character(int hp, int attack, int defense, int mitigation, double dodge, const char* name)
		: show(nullptr), ss(nullptr), m_hp(hp), m_attackPower(attack), m_defensePower(defense), m_mitigation(mitigation),
		m_dodge(dodge), m_name(new char[strlen(name) + 1]) {
		show = new const char* [DODGE + 1];
		ss = new std::stringstream[DODGE + 1];

		strcpy_s((char*)m_name, strlen(name) + 1, name);
	} // コンストラクタ

    Character(const Character& other)
		: show(nullptr), ss(nullptr), m_hp(other.m_hp), m_attackPower(other.m_attackPower), m_defensePower(other.m_defensePower),
		m_mitigation(other.m_mitigation), m_dodge(other.m_dodge) {
		if (show == nullptr) show = new const char* [DODGE + 1];

		if (ss == nullptr) ss = new std::stringstream[DODGE + 1];

		New(other.m_name);
	} // コピーコンストラクタ

	~Character() {
		if (m_name != nullptr) { delete[] m_name; m_name = nullptr; } // 名前のメモリを解放

		if (show != nullptr) { delete[] show; show = nullptr; }

		if (ss != nullptr) { delete[] ss; ss = nullptr; } //stringstreamのメモリを解放

	} // デストラクタ

	void SetParamatorShow(); //パラメーター表示設定メソッド

	void ParamatorShow() const; // パラメータ表示
	const char** GetParamatorShow() const { return show; } //パラメーター表示取得メソッド
	void HpShow() const; // HP表示

	int GetShowString_End() { return DODGE; }

	bool attack(Character* const target); // 攻撃

	bool isAlive() const { return m_hp > 0; } // 生存確認
};