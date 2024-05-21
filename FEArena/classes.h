#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <fstream>
#include <string.h>
#include "stats.h"

#define CLASS_NAME_LENGTH 10

class CharacterClass {
	// Class ID and Class Name
	int classID;
	std::string name;
	// Promoted class
	bool promoted;
	// Class stats
	Stats stats;
public:
	// ******** CONSTRUCTORS ********* //
	CharacterClass();
	CharacterClass(int i, std::string n, bool p, Stats& s);
	CharacterClass(CharacterClass& other);
	// ******** OVERLOADS ********* //
	CharacterClass& operator=(CharacterClass& other);
	// ******** FILE I/O ********* //
	void importClass(std::ifstream& filename);
	// ******** DISPLAY ********* //
	void display();
	void lineHeader();
	void lineDisplay();
};

#endif
