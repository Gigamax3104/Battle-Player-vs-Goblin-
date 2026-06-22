#include	"../h/Enemy.h"
#include	<cstdlib>
#include	<ctime>
using namespace std;

void Enemy::Item(InputManager* input) { if (*m_item != 0) return; m_hp += 10; }


void Enemy::ParamaterShow(InputManager* input) {
	input->SetCursorPosition(Vector2(5, 0));

	cout << m_name;

	input->SetCursorPosition(Vector2(4, 1));
	input->ClearStringLate();

	cout << "HP : " << m_hp << endl;
}
