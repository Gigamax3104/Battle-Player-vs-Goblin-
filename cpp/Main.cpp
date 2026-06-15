#include	"../h/Player.h"
#include	"../h/Enemy.h"
#include	"../h/InputManager.h"

using namespace std;

enum CHARACTER { ENEMY, PLAYER };
const int characterNumber(PLAYER + 1);

bool Game(Character** ch,InputManager* input,const int* number) {
	static int liveNumber(number[ENEMY]);

	Enemy* ch_e = dynamic_cast<Enemy*>(ch[ENEMY]);
	Player* ch_p = dynamic_cast<Player*>(ch[PLAYER]);

	for (int i = 0; i < number[PLAYER]; i++) {
		PlayerState::STATE state = ch_p[i % number[PLAYER]].Choice(input);

		ch_p[i % number[PLAYER]].DeleteString(input);

		switch (state) {
		case PlayerState::STATE::ATTACK:
			if(!ch_e[i].Dodge()) ch_e[i].Damage(ch_p[i].Player_Attack(input));
			break;
		}
	}//プレイヤーの攻撃まで

	if (!ch_e->IsArive()) { liveNumber--; if (liveNumber == 0) return false; }

	return true;
}

int main() {
	int* number = new int[characterNumber];
	number[ENEMY] = 1;
	number[PLAYER] = 1;

	InputManager input;

	Character** ch(new Character*[characterNumber]);

	ch[ENEMY] = new Enemy[number[ENEMY]];

	ch[PLAYER] = new Player[number[PLAYER]];

	for (int i = 0; i < characterNumber; i++) ch[i]->ParamaterShow(&input);

	while (Game(ch, &input, number)) {}

	if (number != nullptr) { delete[] number; number = nullptr; }

	if (ch != nullptr) {
		for (int i = 0; i < characterNumber; i++) if (ch[i] != nullptr) { delete[] ch[i]; ch[i] = nullptr; }

		delete[] ch; ch = nullptr;
	}

	return 0;
}