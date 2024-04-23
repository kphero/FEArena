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
	delete characterClass;
	delete[] inventory;
}

// ********** GETTERS ********** //

// ********** SETTERS ********** //

// ********** DISPLAY ********** //
void Character::displayStats() {
	std::cout << "|---------- STATS ----------|" << std::endl;
	std::cout << "| (1) HP: " << stats.getStats(7) << " / " << stats.getStats(0) + characterClass->stats.getStats(0) << std::endl;
	std::cout << "| (2) STR/MAG: " << stats.getStats(1) + characterClass->stats.getStats(1) << std::endl;
	std::cout << "| (3) SKL: " << stats.getStats(2) + characterClass->stats.getStats(2) << std::endl;
	std::cout << "| (4) SPD: " << stats.getStats(3) + characterClass->stats.getStats(3) << std::endl;
	std::cout << "| (5) LUK: " << stats.getStats(4) + characterClass->stats.getStats(4) << std::endl;
	std::cout << "| (6) DEF: " << stats.getStats(5) + characterClass->stats.getStats(5) << std::endl;
	std::cout << "| (7) RES: " << stats.getStats(6) + characterClass->stats.getStats(6) << std::endl;
	std::cout << "|     TOTAL: " << stats.getTotalStats() + characterClass->stats.getTotalStats() << std::endl;
	std::cout << "|---------------------------|" << std::endl;
}

void Character::displayGrowths() {
	std::cout << "|--------- GROWTHS ---------|" << std::endl;
	std::cout << "| (1) HP: " << stats.growthRates[0] + characterClass->stats.growthRates[0] << std::endl;
	std::cout << "| (2) STR/MAG: " << stats.growthRates[1] + characterClass->stats.growthRates[1] << std::endl;
	std::cout << "| (3) SKL: " << stats.growthRates[2] + characterClass->stats.growthRates[2] << std::endl;
	std::cout << "| (4) SPD: " << stats.growthRates[3] + characterClass->stats.growthRates[3] << std::endl;
	std::cout << "| (5) LUK: " << stats.growthRates[4] + characterClass->stats.growthRates[4] << std::endl;
	std::cout << "| (6) DEF: " << stats.growthRates[5] + characterClass->stats.growthRates[5] << std::endl;
	std::cout << "| (7) RES: " << stats.growthRates[6] + characterClass->stats.growthRates[6] << std::endl;
	std::cout << "|     TOTAL: " << stats.getTotalGrowths() + characterClass->stats.getTotalGrowths() << std::endl;
	std::cout << "|---------------------------|" << std::endl;
}

void Character::displayStatsAndGrowths() {
	//TODO
}


// ********** OPERATORS ********** //

// ********** FUNCTIONS ********** //
void Character::setNewChar() {
	alive = true;
	exp = 0;
	level = 1;
	gold = 100.0;
}

Character& Character::createChar() {
	// Sets character to alive, level 1 with 0 exp
	setNewChar();

	// Enter name, month TODO: Validation
	std::cout << "Enter name: ";
	std::cin >> name;

	std::cout << "Enter Birth month (1-12): ";
	std::cin >> birthMonth;

	// Choose base class TODO: Display options
	std::cout << "Choose a class: ";
	std::cin >> classID;
	// TODO: Switch statement to create a class

	// Display basestats and add points
	displayStats();
	do {
		int inc, amt;

		std::cout << NEW_BASE_TOTAL - (stats.getTotalStats() + characterClass->stats.getTotalStats()) << " point(s) left over. Choose a stat to increase: ";
		std::cin >> inc;

		std::cout << "Increase amount: ";
		std::cin >> amt;

		if (amt <= NEW_BASE_TOTAL - (stats.getTotalStats() + characterClass->stats.getTotalStats())) {
			stats.baseStats[inc - 1] += amt;
			stats.totalStats += amt;
		}
		else {
			std::cout << "Error: Incorrect amount received.\n" << std::endl;
		}

	} while (NEW_BASE_TOTAL > (stats.getTotalStats() + characterClass->stats.getTotalStats()));

	// Display growths and add points
	displayGrowths();
	do {
		int inc, amt;

		std::cout << NEW_GROWTH_TOTAL - (stats.getTotalGrowths() + characterClass->stats.getTotalGrowths()) << " point(s) left over. Choose a growth to increase: ";
		std::cin >> inc;

		std::cout << "Increase amount: ";
		std::cin >> amt;

		if (amt <= NEW_GROWTH_TOTAL - (stats.getTotalGrowths() + characterClass->stats.getTotalGrowths())) {
			stats.growthRates[inc - 1] += amt;
			stats.totalGrowths += amt;
		}
		else {
			std::cout << "Error: Incorrect amount received.\n" << std::endl;
		}

	} while (NEW_GROWTH_TOTAL > (stats.getTotalGrowths() + characterClass->stats.getTotalGrowths()));



}