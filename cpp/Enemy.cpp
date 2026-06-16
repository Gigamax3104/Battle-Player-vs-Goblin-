#include	"../h/Enemy.h"
#include	<cstdlib>
#include	<ctime>
using namespace std;

int Enemy::Attack() { return m_power; }

double Enemy::Action() { return 0.0; }

void Enemy::Item() { if (m_item == 0) return; m_hp += 10; }

void Enemy::Guard() { m_difence *= 1.5; }

bool Enemy::Dodge() { srand((unsigned int)time(NULL)); int dodgeChance = rand() % 100 + 1; return dodgeChance <= m_dodgeProbability; }

void Enemy::Damage(int damage) { m_hp -= damage; if (m_hp < 0) m_hp = 0; cout << m_name << ": HP :" << m_hp << endl; }

bool Enemy::IsArive() const { return m_hp <= 0; }

void Enemy::ParamaterShow(InputManager* input) {
	input->SetCursorPosition(Vector2(5, 0));

	cout << m_name;

	input->SetCursorPosition(Vector2(4, 1));

	cout << m_name << "HP : " << m_hp << endl;
}
