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
	for (int i = 0; i < STATS_LENGTH - 1; i++) {
		std::cout << "| (" << i + 1 << " " << std::setw(3) << statNames[i] << ": ";
		std::cout << stats.getStats(i) + characterClass.stats.getStats(i) << std::endl;
	}
	std::cout << "|     TOTAL: " << stats.getTotalStats() + characterClass.stats.getTotalStats() << std::endl;
	std::cout << "|---------------------------|" << std::endl;
}

void Character::displayGrowths() {
	std::cout << "|--------- GROWTHS ---------|" << std::endl;
	for (int i = 0; i < STATS_LENGTH - 1; i++) {
		std::cout << "| (" << i + 1 << " " << std::setw(3) << statNames[i] << ": ";
		std::cout << stats.getGrowths(i) + characterClass.stats.getGrowths(i) << std::endl;
	}
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
		std::cout << "[Enter name (Max " << CHAR_NAME_LENGTH << " characters)]" << std::endl << "> ";
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
		std::cout << "[Enter Birth month (1-12)]" << std::endl << "> ";
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
	std::cout << "---------------------------------------- CLASSES ----------------------------------------\n";
	classes[0].lineHeader();
	for (int i = 0; i < max; i++) {
		std::cout << "(" << std::setw(2) << i + 1 << ") ";
		classes[i].lineDisplay();
	}
	do {
		std::cout << "[Choose a class]" << std::endl << "> ";
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
		std::cout << "[" << NEW_BASE_TOTAL - (stats.getTotalStats() + characterClass.stats.getTotalStats()) 
				  << " point(s) left over. Choose a stat to increase]" << std::endl << "> ";
		std::cin >> inc;

		std::cout << "[Add how many points to " << statNames[inc - 1] << "]" << std::endl << "> ";
		std::cin >> amt;

		if (amt <= NEW_BASE_TOTAL - (stats.getTotalStats() + characterClass.stats.getTotalStats())) {
			stats.addStats(amt, inc - 1);
			stats.addTotalStats(amt);
		}
		else {
			std::cout << "Error: Incorrect amount received.\n" << std::endl;
		}

	} while (NEW_BASE_TOTAL > (stats.getTotalStats() + characterClass.stats.getTotalStats()));

	// Display growths and add points
	do {
		int inc, amt;

		displayGrowths();
		std::cout << "[" << NEW_GROWTH_TOTAL - (stats.getTotalGrowths() + characterClass.stats.getTotalGrowths()) 
				  << " point(s) left over. Choose a growth to increase]" << std::endl << "> ";
		std::cin >> inc;

		std::cout << "[Add how much percentage to " << statNames[inc - 1] << "]" << std::endl << "> ";
		std::cin >> amt;

		if (amt <= NEW_GROWTH_TOTAL - (stats.getTotalGrowths() + characterClass.stats.getTotalGrowths())) {
			stats.addGrowths(amt, inc - 1);
			stats.addTotalGrowths(amt);
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
		//Extract class
		this->characterClass.importClass(file);
	}
}

void Character::saveCharacter(std::ifstream& file) {

}