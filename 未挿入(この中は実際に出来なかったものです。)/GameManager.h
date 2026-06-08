#pragma once
#include	"Character.h"
#include	"Enemy.h"
#include	"InputManager.h"
#include	"Player.h"
#include	"TextWindow.h"
#include	"Vector2.h"

#define A_KEY 65
#define D_KEY 68
#define LEFT_KEY 75
#define RIGHT_KEY 77

#define ENTER_KEY 13

#define HORIZONTAL_TEXT '-'
#define VIRTUAL_TEXT '|'

class GameManager {
public:
	GameManager(); // コンストラクタ(1対1対応)

	//GameManager(int playerNumber, int enemyNumber); //引数付きコンストラクタ(複数対応な為、今回はなし)

	~GameManager() { // デストラクタ
		if (m_player != nullptr) { delete[] m_player; m_player = nullptr; } // プレイヤーのメモリを解放
		if (m_player_input_window != nullptr) { delete[] m_player_input_window; m_player_input_window = nullptr; }

		if (m_enemy != nullptr) { delete m_enemy; m_enemy = nullptr; }// 敵のメモリを解放

		if (m_number != nullptr) { delete[] m_number; m_number = nullptr; } //味方・敵の数のメモリを解放
	}

	bool Battle(); // 戦闘処理

	void Update(); // ゲームの更新(プレイヤー・敵の変更)
	void Update(int playerNumber, int enemyNumber); //引数付き更新(プレイヤー・敵の数変更)

	void Show();

private:
	int* m_number; //味方・敵の数

	Player* m_player; //プレイヤーのポインタ
	TextWindow m_player_window; //プレイヤーのテキストウインドウ
	TextWindow* m_player_input_window; //選択画面ウインドウ

	Enemy* m_enemy; //敵のポインタ
	TextWindow m_enemy_window; //敵のテキストウインドウ

	InputManager m_input; //入力管理クラスのインスタンス

	enum NUMBER {
		PLAYER = 0, //プレイヤー
		ENEMY //敵
	};

	enum CHOOSE {
		ATTACK = 0, //攻撃
		ACTION, //行動
		ITEM, // アイテム
		GARD // 防御
	};

	CHOOSE Choice(); // プレイヤーの行動選択
};