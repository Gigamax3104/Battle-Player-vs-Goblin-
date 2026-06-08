#include	<iostream>
#include	"../h/Player.h"
#include	"../h/Enemy.h"

using namespace std;

int main() {
	Player player;
	Enemy enemy;

	player.Show();
	enemy.Show();
	cout << "-----------------------------" << endl;

	while (player.isAlive() && enemy.isAlive()) {
		cout << "Player's turn to attack!" << endl;
		player.attack(enemy);
		if (!enemy.isAlive()) {
			cout << "Enemy has been defeated! You win!" << endl;
			break;
		}
		cout << "Enemy's turn to attack!" << endl;
		enemy.attack(player);
		if (!player.isAlive()) {
			cout << "Player has been defeated! Game over!" << endl;
			break;
		}
		cout << "-----------------------------" << endl;
	}

	return 0;
}