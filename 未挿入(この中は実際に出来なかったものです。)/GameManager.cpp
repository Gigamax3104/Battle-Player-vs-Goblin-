#include	"GameManager.h"
#include	<iostream>
#include	<conio.h>
#include	<Windows.h>

using namespace std;

bool GameManager::Battle() {
	static int a(0);

	if (a == 1800) return false;

	Show();
	a++;

	return true;
}

void GameManager::Show() {
	m_input.ResetCursorPosition(); // カーソルの位置をリセット

	m_input.SetCursorPosition(m_player_window.GetWindowPos());
	cout << m_player_window.GetTextWindow();

	m_input.SetCursorPosition(m_player_input_window->GetWindowPos());
	cout << m_player_input_window->GetTextWindow();

	m_input.SetCursorPosition(m_enemy_window.GetWindowPos());
	cout << m_enemy_window.GetTextWindow();
}

GameManager::CHOOSE GameManager::Choice() {
	static int input = ATTACK;

	cout << "Choose your action:" << endl;

	while (1) {
		if (_kbhit()) { // キーが押されたかどうかをチェック
			int key = _getch() - '0'; // キー入力を整数に変換

			//左
			if (key == LEFT_KEY || key == A_KEY) input = (input - 1) % (GARD + 1);

			//右
			else if (key == RIGHT_KEY || key == D_KEY) input = (input + 1) % (GARD + 1);

			// アイテム選択(入力された数値をCHOOSE列挙型に変換して返す。)
			// (static_castを使用して、整数値をCHOOSE列挙型に安全に変換しています。)
			else if (key == ENTER_KEY) {
				input = ATTACK;

				return static_cast<CHOOSE>(input);
			}
		}
	}
}

GameManager::GameManager() : m_player(new Player()), m_enemy(new Enemy()), m_number(new int[2]),m_player_input_window(new TextWindow[1]) {
	m_number[PLAYER] = 1; // プレイヤーの数を初期化
	m_number[ENEMY] = 1; // 敵の数を初期化

	//プレイヤー側と選択画面のウインドウの設計
	m_player_window.SetDivisionWindow(Vector2(30, 50), HORIZONTAL_TEXT, VIRTUAL_TEXT);
	m_player_input_window->SetDivisionWindow(Vector2(20, 25), HORIZONTAL_TEXT, VIRTUAL_TEXT);

	//敵側のウインドウの設計
	m_enemy_window.SetDivisionWindow(Vector2(30, 50), HORIZONTAL_TEXT, VIRTUAL_TEXT);

	//プレイヤー側と選択画面のウインドウの位置(y座標は0)
	m_player_window.SetShowPosition(Vector2(3, 0));

	m_player_input_window->SetShowPosition(Vector2(m_player_window.GetWindowScale().x + m_player_window.GetWindowPos().x + 1, 0));

	//敵側のウインドウの位置
	m_enemy_window.SetShowPosition(
		Vector2(m_player_input_window->GetWindowScale().x / 2 - m_enemy_window.GetWindowScale().x / 2, 0));

	//プレイヤー側と選択画面のウインドウの位置変更(yを主に変更)
	m_player_window.AddShowPosition(Vector2(0, m_enemy_window.GetWindowScale().y + m_enemy_window.GetWindowScale().y / 2));

	m_player_input_window->AddShowPosition(Vector2(0,
		m_player_window.GetWindowPos().y + (m_player_window.GetWindowScale().y - m_player_input_window->GetWindowScale().y) / 2));

	//プレイヤー・敵側のウインドウの中身を文字列で埋める
	for (int i = 0; i <= m_player->GetShowString_End(); i++)
		m_player_window.EmbedString(m_player->GetParamatorShow()[i], Vector2(1, i + 1));

	for (int i = 0; i <= m_enemy->GetShowString_End(); i++)
		m_enemy_window.EmbedString(m_enemy->GetParamatorShow()[i], Vector2(1, i + 1));

	m_input.SetCursorPosition(m_enemy_window.GetWindowPos());
}

//GameManager::GameManager(int playerNumber, int enemyNumber)
//	: m_player(new Player[playerNumber]), m_enemy(new Enemy[enemyNumber]), m_number(new int[2]),m_player_input_window(new TextWindow[playerNumber]) {
//	m_number[PLAYER] = playerNumber; // プレイヤーの数を設定
//	m_number[ENEMY] = enemyNumber; // 敵の数を設定
//
//	//プレイヤー側と選択画面のウインドウの設計
//	m_player_window.SetDivisionWindow(Vector2(31 * playerNumber, 50), HORIZONTAL_TEXT, VIRTUAL_TEXT);
//
//	for(int i = 0; i < playerNumber; i++)
//	m_player_input_window[i].SetDivisionWindow(Vector2(20, 25), HORIZONTAL_TEXT, VIRTUAL_TEXT);
//
//	//敵側のウインドウの設計
//	m_enemy_window.SetDivisionWindow(Vector2(31 * enemyNumber, 50), HORIZONTAL_TEXT, VIRTUAL_TEXT);
//
//	//プレイヤー側と選択画面のウインドウの位置(y座標は0)
//	m_player_window.SetShowPosition(Vector2(0, 0));
//
//	for(int i = 0; i < playerNumber; i++)
//	m_player_input_window[i].SetShowPosition(Vector2(m_player_window.GetWindowScale().x + m_player_window.GetWindowPos().x + 1, 0));
//
//	//敵側のウインドウの位置
//	m_enemy_window.SetShowPosition(
//		Vector2(m_player_input_window.GetWindowScale().x / 2 - m_enemy_window.GetWindowScale().x / 2, 0));
//
//	//プレイヤー側と選択画面のウインドウの位置変更(yを主に変更)
//	m_player_window.AddShowPosition(Vector2(0, m_enemy_window.GetWindowScale().y + m_enemy_window.GetWindowScale().y / 2));
//
//	m_player_input_window.AddShowPosition(Vector2(0,
//		m_player_window.GetWindowPos().y + (m_player_window.GetWindowScale().y - m_player_input_window.GetWindowScale().y) / 2));
//
//	for (int i = 0; i < m_number[PLAYER]; i++)
//		for (int j = 0; j < m_player[i].GetShowString_End(); j++)
//			m_player_window.EmbedString(m_player[i].GetParamatorShow()[j], Vector2(30 * i + 1, i + 1));
//
//	for (int i = 0; i < m_number[ENEMY]; i++)
//		for (int j = 0; j < m_enemy[i].GetShowString_End(); j++)
//			m_enemy_window.EmbedString(m_enemy[i].GetParamatorShow()[j], Vector2(30 * i + 1, i + 1));
//}

void GameManager::Update() {
	delete m_player; // プレイヤーのメモリを解放
	delete m_enemy; // 敵のメモリを解放

	m_player = new Player(); // 新しいプレイヤーを作成
	m_enemy = new Enemy(); // 新しい敵を作成
}

void GameManager::Update(int playerNumber, int enemyNumber) {
	delete m_player; // プレイヤーのメモリを解放
	delete m_enemy; // 敵のメモリを解放

	m_player = new Player[playerNumber]; // 新しいプレイヤーを作成
	m_enemy = new Enemy[enemyNumber]; // 新しい敵を作成
}