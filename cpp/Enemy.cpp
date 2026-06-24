#include	"../h/Enemy.h"
#include	<cstdlib>
#include	<ctime>
using namespace std;

void Enemy::ChoiceBase(Character* ch, InputManager* input) {
	srand((unsigned int)time(NULL));

	int r = rand() % 4;

	if (r == ATTACK) { if (!ch->Dodge()) ch->Damage((int)Attack()); }
	else if (r == ACTION) ch->ChangePower(Action());
	else if (r == ITEM) Item();
	else Guard();
}

void Enemy::Item(InputManager* input) { if (*m_item != 0) return; m_hp += 10; }


void Enemy::ParamaterShow(InputManager* input) {
	input->SetCursorPosition(Vector2(5, 0));

	cout << m_name;

	input->SetCursorPosition(Vector2(4, 1));
	input->ClearStringLate();

	cout << "HP : " << m_hp << endl;
}
