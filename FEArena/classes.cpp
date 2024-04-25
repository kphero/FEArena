#include "classes.h"
#include <fstream>

CharacterClass::CharacterClass(std::string n, bool p, Stats& s) {
	if (n.length() < CLASS_NAME_LENGTH) {
		name.assign(n);
	}

	promoted = p;

	stats = s;
}