#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <iostream>
#include <string.h>
#include "classes.h"
#include "stats.h"
#include "items.h"

// ********** MACROS ********** //
#define CHAR_NAME_LENGTH 20
#define MAX_INVENTORY 5
// New character limits
#define NEW_BASE_TOTAL 60
#define NEW_GROWTH_TOTAL 300

// ********** CLASS ********** //
class Character {
	// Name and affinity
	std::string name;
	int birthMonth;
	// Level and experience
	int level;
	int exp;
	// Stats and growth rates
	Stats stats;
	// Class
	int classID;
	CharacterClass* characterClass;
	// Gold and Inventory, max 5 items
	double gold;
	Item* inventory[MAX_INVENTORY];
	// Is character alive; can be revived with an item
	bool alive;
public:
	// ********** CONSTRUCTORS ********** //
	Character();
	Character(std::string n, int bm, Stats s, CharacterClass& c);
	// ********** DESTRUCTOR ********** //
	~Character();

	// ********** GETTERS ********** //

	// ********** SETTERS ********** //

	// ********** DISPLAY ********** //
	void displayStats();
	void displayGrowths();
	void displayStatsAndGrowths();
	// ********** OPERATORS ********** //

	// ********** FUNCTIONS ********** //
	void setNewChar();
	Character& createChar();
};



#endif
