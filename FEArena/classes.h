#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string.h>
#include "stats.h"

#define CLASS_NAME_LENGTH 10

class CharacterClass {
	int classID;
	std::string name;
	bool promoted;
public:
	Stats stats;
	CharacterClass(std::string n, bool p, Stats& s);
	void ImportClasses(char* filename);
};

#endif
