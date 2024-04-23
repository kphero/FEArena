#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string.h>
#include "stats.h"

#define MAX_NAME_LENGTH 10

class CharacterClass {
	std::string name;
	bool promoted;
public:
	Stats stats;
};

#endif
