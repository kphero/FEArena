#include "classes.h"
#include <fstream>

CharacterClass::CharacterClass() {
	name.assign("");
	classID = -1;
	promoted = false;
}

CharacterClass::CharacterClass(int i, std::string n, bool p, Stats& s) {
	if (n.length() < CLASS_NAME_LENGTH) {
		name.assign(n);
	}

	classID = i;

	promoted = p;

	stats = s;
}

void CharacterClass::importClass(std::ifstream& file) {
	char tempName[CLASS_NAME_LENGTH + 1];
	int temp;
	
	if (file) {
		if (file.is_open()) {
			// Extract ID
			file >> this->classID;
			file.ignore(1000, ',');

			// Extract Name
			file.get(tempName, CLASS_NAME_LENGTH + 1, ',');
			file.ignore(1000, ',');
			this->name.assign(tempName);

			// Extract boolean
			file >> temp;
			file.ignore(1000, ',');
			this->promoted = temp;

			// Extract stats
			for (int i = 0; i < STATS_LENGTH; i++) {
				file >> this->stats.baseStats[i];
				file.ignore(1000, ',');
				this->stats.totalStats += this->stats.baseStats[i];
			}

			for (int i = 0; i < GROWTHS_LENGTH; i++) {
				file >> this->stats.growthRates[i];
				file.ignore(1000, ',');
				this->stats.totalGrowths += this->stats.growthRates[i];
			}

			for (int i = 0; i < RANKS_LENGTH; i++) {
				file >> this->stats.weaponRanks[i];
				if (i == RANKS_LENGTH - 1) {
					file.ignore(1000, '\n');
				}
				else {
					file.ignore(1000, ',');
				}
			}

			// Fill-in other stats
			this->stats.currentHP = this->stats.baseStats[0];
		}
	}
}