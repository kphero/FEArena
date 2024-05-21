#include "classes.h"
#include <fstream>

// ******** CONSTRUCTORS ********* //
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

CharacterClass::CharacterClass(CharacterClass& other) {
	*this = other;
}

// ******** OVERLOADS ********* //
CharacterClass& CharacterClass::operator=(CharacterClass& other) {
	this->classID = other.classID;
	this->name.assign(other.name);
	this->promoted = other.promoted;
	this->stats = other.stats;

	return *this;
}

// ******** FILE I/O ********* //
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
				int n;
				file >> n;
				this->stats.addStats(i, n);
				this->stats.addTotalStats(n);
				file.ignore(1000, ',');
			}

			for (int i = 0; i < GROWTHS_LENGTH; i++) {
				int n;
				file >> n;
				this->stats.addGrowths(i, n);
				this->stats.addTotalGrowths(n);
				file.ignore(1000, ',');
			}

			for (int i = 0; i < RANKS_LENGTH; i++) {
				int n;
				file >> n;
				this->stats.addRanks(i, n);
				if (i == RANKS_LENGTH - 1) {
					file.ignore(1000, '\n');
				}
				else {
					file.ignore(1000, ',');
				}
			}
		}
	}
}

// ******** DISPLAY ********* //
void CharacterClass::display() {
	std::cout << "Class: " << this->name << " | Promoted: " << ((this->promoted == true) ? "Yes\n" : "No\n") << std::endl;
	this->stats.display();
}

void CharacterClass::lineHeader() {
	std::cout << "     |" << std::left << std::setw(CLASS_NAME_LENGTH) << "NAME" << "|";
	this->stats.lineHeader();
}

void CharacterClass::lineDisplay() {
	std::cout << std::left << "|" << std::setw(CLASS_NAME_LENGTH) << this->name << "|";
	this->stats.lineDisplay();
}