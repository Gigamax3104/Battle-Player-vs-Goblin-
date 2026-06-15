#include	"../h/InputManager.h"

void InputManager::SetCursor() {
    // コンソールの標準出力ハンドルを取得
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // 座標を設定 (X: 列, Y: 行)
    COORD pos = { static_cast<SHORT>(m_cursor.x), static_cast<SHORT>(m_cursor.y) };


    //                    ※なお、y座標に限り、下から上へ変更すると奇妙なことになる可能性がある。
    //    カーソル変更    それは、プログラムの終わりが例えば、y座標が0だとすると、その下に文字が入る。
    //                    故に、その前にカーソルを移動した後の文字が消えてしまう為、下から上は後に呼ばなければならない。

    SetConsoleCursorPosition(hConsole, pos);
}

const COORD InputManager::GetCursorPosition_Console() const {
    // コンソールの標準出力ハンドルを取得
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // 画面情報を格納する構造体
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    // 情報を取得
    if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        // csbi.dwCursorPosition に現在の座標（X, Y）が入っています
        return csbi.dwCursorPosition;
    }

    // エラー時は (0, 0) を返す
    return COORD{ 0, 0 };
}
