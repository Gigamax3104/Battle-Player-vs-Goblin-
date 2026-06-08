#include	<cstring>
#include	"TextWindow.h"

void  TextWindow::SetAllWindow(char text, const Vector2& frameWork) {
	if (window != nullptr) { delete[] window; window = nullptr; } //ヌルチェック

	if (text > '~') {
		window = new char[frameWork.MultiplicationMargin_Multi()];

		scale = Vector2(frameWork.x + 2,frameWork.y + 1);
	}
	else {
		window = new char[frameWork.MultiplicationMargin()];

		scale = Vector2(frameWork.x + 1, frameWork.y + 1);
	}

	for (int i = 0; i < frameWork.MultiplicationMargin(); i++) { //ウインドウ設計
		if (i % frameWork.x == frameWork.x) window[i] = '\n'; //ウインドウの一番右の次に改行
		else if (i == frameWork.MultiplicationMargin() - 1) window[i] = '\0'; //最後はヌルターミネーター
		else if (i / frameWork.x == 0 || i % frameWork.x == 0
			|| i % frameWork.x == frameWork.x - 1 || i / frameWork.x == frameWork.y) { //一番上・一番左・一番右・一番下を文字で埋める
			if (text > '~') {
				char multi[2] = { text , '\0' };
				strcpy_s(&window[i], frameWork.MultiplicationMargin() - i, multi); //日本語等の2バイト用のコピー関数
			}
			else window[i] = text; //文字埋め
		}
	}
}

void TextWindow::SetDivisionWindow(const Vector2& frameWork, char horizontalText, char virtualText) {
	if (window != nullptr) { delete[] window; window = nullptr; }

	window = new char[frameWork.MultiplicationMargin()];

	for (int i = 0; i < frameWork.MultiplicationMargin(); i++) {
		if (i % frameWork.x == frameWork.x) window[i] = '\n';
		else if (i == frameWork.MultiplicationMargin() - 1) window[i] = '\0';
		else if (i / frameWork.x == 0 || i / frameWork.x == frameWork.y) {
			if (horizontalText > '~') strcpy_s(&window[i], strlen(window), &horizontalText); //一番上・一番下はhorizontalTextで埋める
			else window[i] = horizontalText;
		}
		else if (i % frameWork.x == 0 || i % frameWork.x == frameWork.x - 1) {
			if (virtualText > '~') strcpy_s(&window[i], strlen(window), &virtualText); //一番左・一番右はvirtualTextで埋める
			else window[i] = virtualText;
		}
	}
}

void TextWindow::EmbedAllText(char text) {
	if (window == nullptr || *window == '\0') return; //もしwindowがヌルだったり、1マスだけの場合は抜ける。

	int windowIndex = 0; //一番左上を起点とする

	while (window[windowIndex] != '\0') {
		if (window[windowIndex] == NULL) window[windowIndex] = text; //windowの中身が何もない時、文字を埋める

		windowIndex++;
	}
}

void TextWindow::EmbedAllString(const char* text) {
	if (window == nullptr || *window == '\0') return;

	enum { WINDOW, TEXT }; //配列要素数の列挙体(ウインドウの中身と文字列の中身)

	int* index = new int[TEXT + 1];
	index[WINDOW] = 0, index[TEXT] = 0;

	while (window[index[WINDOW]] != '\0') {
		if (window[index[WINDOW]] == NULL) {
			window[index[WINDOW]] = text[index[TEXT]]; //こちらは文字列の1文字を埋める

			index[TEXT] = (window[index[TEXT]] + 1) % strlen(text);
		}

		index[WINDOW]++;
	}
}

void TextWindow::EmbedText(char text, const Vector2& position) {
	if (window == nullptr || *window == '\0') return;

	int windowIndex = position.Multiplication(); //指定した位置を起点とする

	while (window[windowIndex] != '\0') {
		if (window[windowIndex] == NULL) window[windowIndex] = text;

		windowIndex++;
	}
}

void TextWindow::EmbedString(const char* text, const Vector2& position) {
	if (window == nullptr || *window == '\0') return;
	if (text == nullptr) return;               // ←追加
	size_t textLen = strlen(text);             // ここで安全に使える

	enum { WINDOW, TEXT }; //配列要素数の列挙体(ウインドウの中身と文字列の中身)

	int* index = new int[TEXT + 1];
	index[WINDOW] = position.Multiplication(), index[TEXT] = 0;
	
	while (index[WINDOW] != '\0' && index[TEXT] != textLen) {
		if (window[index[WINDOW]] == NULL) {
			window[index[WINDOW]] = text[index[TEXT]];

			index[TEXT]++;
		}

		index[WINDOW]++;
	}
}