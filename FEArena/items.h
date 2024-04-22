#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string.h>

class Item {
	std::string name;
	int weaponID; // 1:Sword, 2:Axe, 3:Lance, 4:Bow
	float range; // 1.0, 2.0, 1.2
	int might;
	int crit;
	int hit;
	int weight;
	char rank; // 'E' to 'S'
	float value;
	int expGiven;
public:
	// ********** CONSTRUCTORS ********** //
	Item();
	Item(std::string name, int id, float rng, int mt, int crt, int ht, int wt, char rnk, float val, int xp);
	Item(Item& other);

	// ********** GETTERS ********** //

	// ********** SETTERS ********** //
	void setEmpty();

	// ********** DISPLAY ********** //
	void displayItem();

	// ********** OPERATORS ********** //
	Item& operator=(Item& other);

	// ********** FUNCTIONS ********** //
	std::string getWeaponType();
};

#endif
