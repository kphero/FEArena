#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <iostream>
#include <string.h>
#include "classes.h"
#include "stats.h"
#include "items.h"

#define MAX_NAME_LENGTH 20

class Character {
	std::string name;
	int age;
	int level;
	int exp;
	Stats stats;
	CharacterClass characterClass;
	Item* inventory;
	bool alive;
public:
	// ********** CONSTRUCTORS ********** //
	Character();
	Character();
	Character(Character& other);

	// ********** DESTRUCTOR ********** //
	~Character();

	// ********** GETTERS ********** //

	// ********** SETTERS ********** //

	// ********** DISPLAY ********** //

	// ********** OPERATORS ********** //

	// ********** FUNCTIONS ********** //
};



#endif
