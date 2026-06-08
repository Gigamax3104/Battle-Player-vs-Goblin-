#pragma once
#include	"Vector2.h"

class TextWindow {
public:
	TextWindow() : window(new char[1]), showPos(0, 0),scale(1,1) { *window = '\0'; } //コンストラクタ
	~TextWindow() { if (window != nullptr) delete[] window; } //デストラクタ

	void SetAllWindow(char text, const Vector2& frameWork); //枠組み(1つのテキスト)
	void SetDivisionWindow(const Vector2& frameWork, char horizontalText, char virtualText); //枠組み(横、縦でテキストが違う)

	void EmbedAllText(char text); //テキストウインドウの中身を文字で埋める(全て)
	void EmbedAllString(const char* text); //テキストウインドウの中身を文字列で埋める(全て)
	void EmbedText(char text, const Vector2& position); //テキストウインドウの中身を文字で埋める(位置を決めることが可能)
	void EmbedString(const char* text, const Vector2& position); //テキストウインドウの中身を文字列で埋める(位置を決めることが可能)

	const char* GetTextWindow() { return window; }

	const Vector2 GetWindowPos() const { return showPos; }

	const Vector2 GetWindowScale() const { return scale; }

	void SetShowPosition(const Vector2& pos) { showPos = pos; }

	void AddShowPosition(const Vector2& pos) { showPos += pos; }

private:
	char* window;

	Vector2 showPos;
	Vector2 scale;
};