#include "spaceship.h"
#include "spaceship.cpp"
#include <iostream>
using namespace std;

void simulateAttacks(Spaceship* ship) {
    weapon attacks[] = {laser, laser, laser, missile, plasma};
    int powers[] = {5, 10, 15, 20, 25};
    for (int i = 0; i < 5; i++) {
        if (ship->isAlive()) {
            ship->hit(attacks[i], powers[i]);
            //ship->status();
        } else {
            break;
        }
    }
}

const void survivedAttacks(Spaceship* ship, shiptype shipType, string shipName){
    if(ship->isAlive()){
        cout << shipTypeToString(shipType) << " " << shipName << " survived!" << endl;
        ship->status();
	}
}

int main() {
    int numShips;
	cin >> numShips;
	cin.ignore(); // To ignore the newline character after the number input
	//Spaceship** fleet = new Spaceship * [numShips];

    for (int i = 0; i < numShips; i++) {

        cout << "#" << i << endl;

		int shipType;
		string name;
		int hull, armor, shields, personnel;
        cin >> shipType;
        cin >> name;
		cin >> hull;
        if (shipType == destroyer || shipType == dreadnought || shipType == dropship) {
            cin >> armor;
        }
        if (shipType == battlecruiser || shipType == dreadnought) {
            cin >> shields;
        }
        if (shipType == dropship) {
            cin >> personnel;
        }
		cin.ignore(); // To ignore the newline character after the last input   

        switch (shipType)
        {
        case frigate:
            Spaceship *f;
			f = new Frigate(name, hull);
			simulateAttacks(f);
			survivedAttacks(f, frigate, name);
			//fleet[i] = f;
			break;
        case destroyer:
			Spaceship* d;
			d = new Destroyer(name, hull, armor);
			simulateAttacks(d);
			survivedAttacks(d, destroyer, name);
			//fleet[i] = d;
            break;
        case battlecruiser:
			Spaceship* bc;
			bc = new Battlecruiser(name, hull, shields);
			simulateAttacks(bc);
			survivedAttacks(bc, battlecruiser, name);
			//fleet[i] = bc;
            break;
		case dreadnought:
            Spaceship* dn;
			dn = new Dreadnought(name, hull, armor, shields);
			simulateAttacks(dn);
			survivedAttacks(dn, dreadnought, name);
			//fleet[i] = dn;
            break;
        case dropship:
            Spaceship* ds;
			ds = new Dropship(name, hull, armor, personnel);
            simulateAttacks(ds);
			survivedAttacks(ds, dropship, name);
            //fleet[i] = ds;
            break;
        default:
            break;
        }
        cout << endl;
    }
    return 0;
}