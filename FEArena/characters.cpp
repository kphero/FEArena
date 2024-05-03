#include "characters.h"

// ********** CONSTRUCTORS ********** //
Character::Character() {
	setNewChar();
	name.assign("");
	birthMonth = 0;
}

Character::Character(std::string n, int bm, Stats s, CharacterClass& c) {
	setNewChar();
	name.assign(n);
	birthMonth = bm;
	stats = s;
}

// ********** DESTRUCTOR ********** //
Character::~Character() {

}

// ********** GETTERS ********** //

// ********** SETTERS ********** //

// ********** DISPLAY ********** //
void Character::displayStats() {
	std::cout << "|---------- STATS ----------|" << std::endl;
	std::cout << "| (1)  HP: " << stats.getStats(0) + characterClass.stats.getStats(0) << std::endl;
	std::cout << "| (2) S/M: " << stats.getStats(1) + characterClass.stats.getStats(1) << std::endl;
	std::cout << "| (3) SKL: " << stats.getStats(2) + characterClass.stats.getStats(2) << std::endl;
	std::cout << "| (4) SPD: " << stats.getStats(3) + characterClass.stats.getStats(3) << std::endl;
	std::cout << "| (5) LUK: " << stats.getStats(4) + characterClass.stats.getStats(4) << std::endl;
	std::cout << "| (6) DEF: " << stats.getStats(5) + characterClass.stats.getStats(5) << std::endl;
	std::cout << "| (7) RES: " << stats.getStats(6) + characterClass.stats.getStats(6) << std::endl;
	std::cout << "|     TOTAL: " << stats.getTotalStats() + characterClass.stats.getTotalStats() << std::endl;
	std::cout << "|---------------------------|" << std::endl;
}

void Character::displayGrowths() {
	std::cout << "|--------- GROWTHS ---------|" << std::endl;
	std::cout << "| (1)  HP: " << stats.growthRates[0] + characterClass.stats.growthRates[0] << std::endl;
	std::cout << "| (2) S/M: " << stats.growthRates[1] + characterClass.stats.growthRates[1] << std::endl;
	std::cout << "| (3) SKL: " << stats.growthRates[2] + characterClass.stats.growthRates[2] << std::endl;
	std::cout << "| (4) SPD: " << stats.growthRates[3] + characterClass.stats.growthRates[3] << std::endl;
	std::cout << "| (5) LUK: " << stats.growthRates[4] + characterClass.stats.growthRates[4] << std::endl;
	std::cout << "| (6) DEF: " << stats.growthRates[5] + characterClass.stats.growthRates[5] << std::endl;
	std::cout << "| (7) RES: " << stats.growthRates[6] + characterClass.stats.growthRates[6] << std::endl;
	std::cout << "|     TOTAL: " << stats.getTotalGrowths() + characterClass.stats.getTotalGrowths() << std::endl;
	std::cout << "|---------------------------|" << std::endl;
}

void Character::displayStatsAndGrowths() {
	//TODO
}


// ********** OPERATORS ********** //

// ********** FUNCTIONS ********** //
void Character::setNewChar() {
	charID = -1;
	alive = true;
	exp = 0;
	level = 1;
	gold = 100.0;
}

void Character::createChar(CharacterClass classes[], int max) {
	int valid = 0;

	// Sets character to alive, level 1 with 0 exp and starting gold
	setNewChar();

	// Enter name, until valid
	do {
		std::cout << "Enter name (Max " << CHAR_NAME_LENGTH << " characters): ";
		std::getline(std::cin, name);

		if (name.length() > CHAR_NAME_LENGTH + 1) {
			std::cout << "Name exceeds character limit!\n" << std::endl;
			valid = 0;
		}
		else {
			valid = 1;
		}

	} while (!valid);

	// Enter birth month, until valid
	do {
		std::cout << "Enter Birth month (1-12): ";
		std::cin >> birthMonth;

		if (birthMonth > 12 || birthMonth < 1) {
			std::cout << "Not a valid birth month!\n" << std::endl;
			valid = 0;
		}
		else {
			valid = 1;
		}

	} while (!valid);

	// Choose base class
	chooseClass(classes, max);

	// Add stats and growths
	addStats();
}

void Character::chooseClass(CharacterClass classes[], int max) {
	int input;
	// Loads in classes object
	std::cout << "CLASSES: \n";
	classes[0].lineHeader();
	for (int i = 0; i < max; i++) {
		std::cout << "(" << std::setw(2) << i + 1 << ") ";
		classes[i].lineDisplay();
	}
	do {
		std::cout << "Choose a class: ";
		std::cin >> input;

		if (input > max || input < 1) {
			std::cout << "Incorrect class chosen, try again (1-" << max << ")" << std::endl;
		}
		else {
			// Update character class object and class ID with valid chosen class
			this->characterClass = classes[input - 1];
			this->classID = input;
		}
	} while (input > max || input < 1);
}

void Character::addStats() {
	// Display basestats and add points
	do {
		int inc, amt;

		displayStats();
		std::cout << NEW_BASE_TOTAL - (stats.getTotalStats() + characterClass.stats.getTotalStats()) << " point(s) left over. Choose a stat to increase: ";
		std::cin >> inc;

		std::cout << "Add how many points to " << stats.statCall(inc - 1) << ": ";
		std::cin >> amt;

		if (amt <= NEW_BASE_TOTAL - (stats.getTotalStats() + characterClass.stats.getTotalStats())) {
			stats.baseStats[inc - 1] += amt;
			stats.totalStats += amt;
		}
		else {
			std::cout << "Error: Incorrect amount received.\n" << std::endl;
		}

	} while (NEW_BASE_TOTAL > (stats.getTotalStats() + characterClass.stats.getTotalStats()));

	// Display growths and add points
	do {
		int inc, amt;

		displayGrowths();
		std::cout << NEW_GROWTH_TOTAL - (stats.getTotalGrowths() + characterClass.stats.getTotalGrowths()) << " point(s) left over. Choose a growth to increase: ";
		std::cin >> inc;

		std::cout << "Add how much percentage to " << stats.statCall(inc - 1) << ": ";
		std::cin >> amt;

		if (amt <= NEW_GROWTH_TOTAL - (stats.getTotalGrowths() + characterClass.stats.getTotalGrowths())) {
			stats.growthRates[inc - 1] += amt;
			stats.totalGrowths += amt;
		}
		else {
			std::cout << "Error: Incorrect amount received.\n" << std::endl;
		}

	} while (NEW_GROWTH_TOTAL > (stats.getTotalGrowths() + characterClass.stats.getTotalGrowths()));
}

void Character::importCharacter(std::ifstream& file) {
	if (file.is_open()) {
		char tempName[CLASS_NAME_LENGTH + 1];
		// Extract ID
		file >> this->charID;
		file.ignore(1000, ',');

		// Extract Name
		file.get(tempName, CLASS_NAME_LENGTH + 1, ',');
		file.ignore(1000, ',');
		this->name.assign(tempName);

		//Extract Birth Month
		file >> this->birthMonth;
		file.ignore(1000, ',');

		//Extract Level
		file >> this->level;
		file.ignore(1000, ',');

		//Extract EXP
		file >> this->exp;
		file.ignore(1000, ',');

		//Extract Gold
		file >> this->gold;
		file.ignore(1000, ',');

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
		//Extract class
		this->characterClass.importClass(file);
	}
}

void Character::saveCharacter(std::ifstream& file) {

}