#include "spaceship.cpp"
#include "SpaceBattleQueue.hpp"
#include <iostream>

using namespace std;

/*void loadQueue(SpaceBattleQueue<Spaceship*> sbq) {


}*/

int main() {
	SpaceBattleQueue<Spaceship*> sbq;
	int numShips;
	cin >> numShips;
	cin.ignore(); // To ignore the newline character after the number input

	for (int i = 0; i < numShips; i++) {
		int shipType;
		string name;
		int hull, armor, shields, personnel, laser_pwr, missile_num, missile_pwr, plasma_pwr;
		cin >> shipType;
		cin >> name;
		cin >> hull;
		switch (shipType) {
			case FRIGATE:
				cin >> laser_pwr;
				cin.ignore();
				Spaceship *f;
				f = new Frigate(name, hull, laser_pwr);
				sbq.enqueue(f);
				break;
			case DESTROYER:
				cin >> armor;
				cin >> laser_pwr;
				cin >> missile_num;
				cin >> missile_pwr;
				cin.ignore();
				Spaceship *d;
				d = new Destroyer(name, hull, armor, laser_pwr, missile_num, missile_pwr);
				sbq.enqueue(d);
				break;
			case BATTLECRUISER:
				cin >> shields;
				cin >> laser_pwr;
				cin >> plasma_pwr;
				cin.ignore();
				Spaceship *b;
				b = new Battlecruiser(name, hull, shields, laser_pwr, plasma_pwr);
				sbq.enqueue(b);
				break;
			case DREADNOUGHT:
				cin >> armor;
				cin >> shields;
				cin >> laser_pwr;
				cin >> missile_num;
				cin >> missile_pwr;
				cin >> plasma_pwr;
				cin.ignore();
				Spaceship *dn;
				dn = new Dreadnought(name, hull, armor, shields, laser_pwr, missile_num, missile_pwr, plasma_pwr);
				sbq.enqueue(dn);
				break;
			case DROPSHIP:
				cin >> armor;
				cin >> personnel;
				cin >> missile_num;
				cin >> missile_pwr;
				cin.ignore();
				Spaceship *dr;
				dr = new Dropship(name, hull, armor, personnel, missile_num, missile_pwr);
				sbq.enqueue(dr);
				break;
		}
	}

	int battleNum = 1;
	while (sbq.size() > 1) {
		Spaceship *p1 = sbq.front();
		sbq.dequeue();
		Spaceship *p2 = sbq.front();
		sbq.dequeue();
		cout << "BATTLE #" << battleNum << " : " << p1->getName() << " vs " << p2->getName() <<  endl;
		while (p1->isAlive() && p2->isAlive()) {
			try {
				p1->fire();
			}
			catch (pair<weapon, int>& shot) {
				p2->hit(shot.first, shot.second);
			}
			if (!p2->isAlive()) {
				// player 1 wins
				sbq.enqueue(p1);
			}
			else {
				try {
					p2->fire();

				} catch (pair<weapon, int>& shot) {
					p1->hit(shot.first, shot.second);
				}
				if (!p1->isAlive()) {
					// player 2 wins
					sbq.enqueue(p2);
				}
			}
		}
		cout << "WINNER: " << sbq.front()->getName() << endl;
		cout << endl;
		battleNum++;
	}
	cout << "CHAMPION: " << sbq.front()->getName() << endl;
	sbq.front()->status();
	return 0;
}