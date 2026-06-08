#pragma once
#include	"Vector2.h"
#include	<iostream>

class InputManager {
public:
	void SetCursorPosition(int x, int y) { m_cursor = Vector2(x, y); SetCursor(); } //カーソルの位置を設定
	void SetCursorPosition(Vector2 position) { m_cursor = position; SetCursor(); }  //同様(Vector2版)

	void ResetCursorPosition() { m_cursor = Vector2(0, 0); SetCursor(); } // カーソルの位置をリセット

private:
	void SetCursor() const { std::cout << "\x1b[" << m_cursor.x << "; " << m_cursor.y << "H"; } //カーソルの位置をコンソールに設定

	Vector2 m_cursor; //カーソルの位置
};