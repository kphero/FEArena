#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <fstream>
#include <string.h>
#include "stats.h"

#define CLASS_NAME_LENGTH 10

class CharacterClass {
	int classID;
	std::string name;
	bool promoted;
public:
	Stats stats;
	CharacterClass();
	CharacterClass(int i, std::string n, bool p, Stats& s);
	// Copy assignment
	CharacterClass& operator=(CharacterClass& other);
	// Imports classes from text file
	void importClass(std::ifstream& filename);
	// Display class
	void display();
	void lineDisplay();
};

#endif
