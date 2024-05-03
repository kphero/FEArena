#ifndef MENU_H
#define MENU_H

#include "characters.h"

#define TOTAL_CHARACTERS 5
#define TOTAL_CLASSES 14

class Menu {
	Character current;
	Character allCharacters[TOTAL_CHARACTERS];
	CharacterClass baseClasses[TOTAL_CLASSES];
public:
	// Load in classes
	void load();
	// Menu
	void header();
	void mainMenu();
	// Main menu options
	void ncMenu();
	void lcMenu();
	void convoyMenu();
	// Once a character is create/loaded in
	void gameMenu(Character& protagonist);
};


#endif