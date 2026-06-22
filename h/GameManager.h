#pragma once
//#include	"Character.h"
//#include	"TextWindow.h"

#include	"Variable.h"
#include	"Enemy.h"
#include	"Player.h"
#include	"InputManager.h"

class GameManager {
public:
	GameManager(); // コンストラクタ(1対1対応)

	GameManager(int, int); //引数付きコンストラクタ(複数対応)

	~GameManager(); //デストラクタ

	bool Battle(); // 戦闘処理

	void Update(); // ゲームの更新(プレイヤー・敵の変更)
	void Update(int, int); //引数付き更新(プレイヤー・敵の数変更)

private:
	int* m_number; //味方・敵の数

	Character** m_character; //キャラクターのポインタ

	InputManager m_input; //入力管理クラスのインスタンス

	enum NUMBER {
		PLAYER = 0, //プレイヤー
		ENEMY //敵
	};
};

//デファインド
//#define HORIZONTAL_TEXT '-'
//#define VIRTUAL_TEXT '|'

//デストラクタ
//if (m_player != nullptr) { delete[] m_player; m_player = nullptr; } // プレイヤーのメモリを解放
//if (m_player_input_window != nullptr) { delete[] m_player_input_window; m_player_input_window = nullptr; }

//if (m_enemy != nullptr) { delete m_enemy; m_enemy = nullptr; }// 敵のメモリを解放

//if (m_number != nullptr) { delete[] m_number; m_number = nullptr; } //味方・敵の数のメモリを解放

//メンバ変数
//TextWindow m_player_window; //プレイヤーのテキストウインドウ
//TextWindow* m_player_input_window; //選択画面ウインドウ

//Enemy* m_enemy; //敵のポインタ
//TextWindow m_enemy_window; //敵のテキストウインドウ