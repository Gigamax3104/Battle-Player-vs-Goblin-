#pragma once
#include	"Vector2.h"
#include	<iostream>

class InputManager {
public:
	InputManager() : m_cursor(0, 0) {}

	void SetCursorPosition(int x, int y) { m_cursor = Vector2(x, y); SetCursor(); } //カーソルの位置を設定
	void SetCursorPosition(Vector2 position) { m_cursor = position; SetCursor(); }  //同様(Vector2版)
	void SetCursorPosition(const COORD& position) { m_cursor = position; SetCursor(); } //同様(COORD版)

	void ResetCursorPosition() { m_cursor = Vector2(0, 0); SetCursor(); } // カーソルの位置をリセット

	const Vector2 GetCursorPosition() const { return m_cursor; }
	const COORD GetCursorPosition_Console() const;

	void ClearStringLate() const { std::cout << "\x1b[0K"; } //カーソルより1行後ろを削除
private:
	void SetCursor(); //カーソルの位置をコンソールに設定

	Vector2 m_cursor; //カーソルの位置
};