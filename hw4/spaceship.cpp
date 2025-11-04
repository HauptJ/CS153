// hw4/spaceship.cpp

#include "spaceship.h"
#include <string>
#include <iostream>
using namespace std;

const string shipTypeToString(shiptype t) {
    switch (t) {
    case frigate: return "Frigate";
    case destroyer: return "Destroyer";
    case battlecruiser: return "Battlecruiser";
    case dreadnought: return "Dreadnought";
    case dropship: return "Dropship";
    default: return "Unknown";
    }
}

const string weaponToString(weapon s) {
    switch (s) {
        case laser: return "laser";
        case missile: return "missile";
        case plasma: return "plasma";
        default: return "unknown";
    }
}

class Frigate : public Spaceship {
public:
    Frigate(string name, int hull)
        : Spaceship(name, hull) {}
    void hit(weapon s, int power) override {
        m_hull -= power;
		if (m_hull < 0) m_hull = 0;
        if (m_hull <= 0) {
			cout << "Frigate " << m_name << " destroyed after weapon " << weaponToString(s) << " power " << power << "." << endl;
        }
	}
    void status() const override {
        cout << "Status: " << m_name << " hull: " << m_hull << "." << endl;
	}
};

class Destroyer : public Spaceship {
private:
    int m_armor;
public:
    Destroyer(string name, int hull, int armor)
        : Spaceship(name, hull), m_armor(armor) {}
    void hit(weapon s, int power) override {
        if (m_armor > 0 && s == missile) {
            m_armor -= power / 2;
			if (m_armor < 0) m_armor = 0;
        }
        else {
            m_hull -= power;
			if (m_hull < 0) m_hull = 0;
        }

        if (m_hull <= 0) {
            cout << "Destroyer " << m_name << " destroyed after weapon " << weaponToString(s) << " power " << power << "." << endl;
        }
    }
    void status() const override {
        cout << "Status: " << m_name << " hull: " << m_hull << ", armor: " << m_armor << "." << endl;
    }
};

class Battlecruiser : public Spaceship {
private:
    int m_shields;
public:
    Battlecruiser(string name, int hull, int shields)
        : Spaceship(name, hull), m_shields(shields) {}
    void hit(weapon s, int power) override {
        if (m_shields > 0 && s != missile) {
            if (s == laser) {
                m_shields -= power / 3;
				if (m_shields < 0) m_shields = 0;
            } 
            else if (s == plasma) {
                m_shields -= power;
				if (m_shields < 0) m_shields = 0;
                m_hull -= power / 2;
				if (m_hull < 0) m_hull = 0;
            }
        }
        else {
            m_hull -= power;
			if (m_hull < 0) m_hull = 0;
        }
        if (m_hull <= 0) {
            cout << "Battlecruiser " << m_name << " destroyed after weapon " << weaponToString(s) << " power " << power << "." << endl;
        }
    }
    void status() const override {
        cout << "Status : " << m_name << " hull: " << m_hull << ", shields: " << m_shields << "." << endl;
    }
};

class Dreadnought : public Spaceship {
private:
    int m_armor;
    int m_shields;
public:
    Dreadnought(string name, int hull, int armor, int shields)
        : Spaceship(name, hull), m_armor(armor), m_shields(shields) {}
    void hit(weapon s, int power) override {
        if (m_armor > 0 && s == missile) {
            m_armor -= power / 2;
			if (m_armor < 0) m_armor = 0;
        }
        else if (m_shields > 0 && s != missile) {
            if (s == laser) {
                m_shields -= power / 3;
				if (m_shields < 0) m_shields = 0;
            }
            else if (s == plasma) {
                m_shields -= power;
				if (m_shields < 0) m_shields = 0;
                m_hull -= power / 2;
				if (m_hull < 0) m_hull = 0;
            }
        }
        else {
			m_hull -= power;
			if (m_hull < 0) m_hull = 0;
        }
        if (m_hull <= 0) {
            cout << "Dreadnaught " << m_name << " destroyed after weapon " << weaponToString(s) << " spower " << power << "." << endl;
        }
	}
    void status() const override {
        cout << "Status : " << m_name << " hull: " << m_hull <<  ", shields: " << m_shields << ", armor: " << m_armor << "." << endl;
	}
};

class Dropship : public Spaceship {
private:
    int m_armor;
	int m_personnel;
public:
    Dropship(string name, int hull, int armor, int personnel)
        : Spaceship(name, hull), m_armor(armor), m_personnel(personnel) {}
    void hit(weapon s, int power) override {
        if (m_armor > 0 && s == missile) {
            m_armor -= power / 2;
        }
        else {
            m_hull -= power;
			if (m_hull < 0) m_hull = 0;
			m_personnel -= m_personnel / 4;
        }
        if (m_hull <= 0) {
            cout << "Dropship " << m_name << " destroyed after weapon: " << weaponToString(s) << " power " << power << "." << endl;
        }
	}
    void status() const override {
        cout << "Status: " << m_name << " hull: " << m_hull << ", armor: " << m_armor << ", personnel: " << m_personnel << "." << endl;
	}
};