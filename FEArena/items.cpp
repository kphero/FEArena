#include "items.h"

// ********** CONSTRUCTORS ********** //
Item::Item() {
	setEmpty();
}

Item::Item(std::string name, int id, float rng, int mt, int crt, int ht, int wt, char rnk, float val, int xp) {
	name.assign(name);
	weaponID = id;
	range = rng;
	might = mt;
	crit = crt;
	hit = ht;
	weight = wt;
	rank = rnk;
	value = val;
	expGiven = xp;
}

Item::Item(Item& other) {
	*this = other;
}

// ********** GETTERS ********** //

// ********** SETTERS ********** //
void Item::setEmpty() {
	name.assign("");
	weaponID = -1;
	range = -1;
	might = -1;
	crit = -1;
	hit = -1;
	weight = -1;
	rank = '?';
	value = -1.0;
	expGiven = -1;
}

// ********** DISPLAY ********** //
void Item::displayItem() {

}

// ********** OPERATORS ********** //
Item& Item::operator=(Item& other) {
	name.assign(other.name);
	weaponID = other.weaponID;
	range = other.range;
	might = other.might;
	crit = other.crit;
	hit = other.hit;
	weight = other.weight;
	rank = other.rank;
	value = other.value;
	expGiven = other.expGiven;
}

// ********** FUNCTIONS ********** //
std::string Item::getWeaponType() {
	std::string wep;

	switch (weaponID) {
	case (1):
		wep.assign("Sword");
		break;
	case (2):
		wep.assign("Axe");
		break;
	case (3):
		wep.assign("Lance");
		break;
	case (4):
		wep.assign("Bow");
		break;
	default:
		wep.assign("Error");
		break;
	}

	return wep;
}