#include "stats.h"

std::string statNames[STATS_LENGTH] = { "HP", "STR", "SKL", "SPD", "LUK", "DEF", "RES", "CON"};
std::string statNamesLong[STATS_LENGTH] = { "Hitpoints", "Strength", "Skill", "Speed", 
										      "Luck", "Defense", "Resistance", "Constitution"};
std::string rankNames[RANKS_LENGTH] = { "SWD", "LNC", "AXE", "BOW", "ANM", "LGT", "DRK", "STF" };
std::string rankNamesLong[RANKS_LENGTH] = {"Sword", "Lance", "Axe", "Bow", "Anima", "Light", "Dark", "Staff"};

// ******** CONSTRUCTORS ********* //
Stats::Stats() {}

Stats::Stats(int b[], int g[], int w[]) {
	for (int i = 0; i < RANKS_LENGTH; i++) {
		weaponRanks[i] = w[i];

		if (i < STATS_LENGTH) {
			baseStats[i] = b[i];
			totalStats += baseStats[i];
		}

		if (i < GROWTHS_LENGTH) {
			growthRates[i] = g[i];
			totalGrowths += growthRates[i];
		}
	}
}

// ******** GETTERS ********* //
Stats::Stats(Stats& other) {
	*this = other;
}

int Stats::getTotalStats() const {
	return totalStats;
}

int Stats::getTotalGrowths() const {
	return totalGrowths;
}

int Stats::getStats(int idx) const {
	return baseStats[idx];
}

int Stats::getGrowths(int idx) const {
	return growthRates[idx];
}

int Stats::getRanks(int idx) const {
	return weaponRanks[idx];
}

// ******** SETTERS ********* //
void Stats::addTotalStats(int n) {
	totalStats += n;
}

void Stats::addTotalGrowths(int n) {
	totalGrowths += n;
}

void Stats::addStats(int idx, int n) {
	baseStats[idx] += n;
}

void Stats::addGrowths(int idx, int n) {
	growthRates[idx] += n;
}

void Stats::addRanks(int idx, int n) {
	weaponRanks[idx] += n;
}

// ******** OVERLOADS ********* //
Stats& Stats::operator=(Stats& other) {
	this->totalStats = other.totalStats;
	this->totalGrowths = other.totalGrowths;

	for (int i = 0; i < RANKS_LENGTH; i++) {
		this->weaponRanks[i] = weaponRanks[i];

		if (i < STATS_LENGTH) {
			this->baseStats[i] = other.baseStats[i];
		}

		if (i < GROWTHS_LENGTH) {
			this->growthRates[i] = other.growthRates[i];
		}
	}

	return *this;
}

// ******** DISPLAY ********* //
void Stats::display() {
	std::cout << "|------ STATS -------|" << std::endl;
	for (int i = 0; i < STATS_LENGTH; i++) {
		// Display stat
		std::cout << "| " << std::setw(4) << statNames[i] << ": [";
		std::cout << std::setw(2) << baseStats[i] << "]";
		// Display growth rate
		if (i < GROWTHS_LENGTH) {
			std::cout << " (" << growthRates[i] << "%) |";
		}
		else {
			std::cout << std::setw(8) << std::right << "|";
		}
		std::cout << std::endl;
	}
	std::cout << "|--------------------|\n" << std::endl;

	std::cout << "|------------- RANKS --------------|" << std::endl << "|";
	for (int i = 0; i < RANKS_LENGTH; i++) {
		if (i == 4) {
			std::cout << std::endl << "|";
		}
		std::cout << rankNames[i] << ": " << wpnRank(i) << " | ";
	}	
	std::cout << "\n|----------------------------------|\n"  << std::endl;
}

void Stats::lineHeader() {
	for (int i = 0; i < STATS_LENGTH; i++) {
		if (i == STATS_LENGTH - 1) {
			std::cout << std::setw(3) << statNames[i] << "|";
		}
		else {
			std::cout << std::setw(8) << statNames[i] << "|";
		}
	}
	std::cout << std::setw(10) << " Weapons" << std::endl;
}

void Stats::lineDisplay() {
	int counter = 0;

	for (int i = 0; i < STATS_LENGTH; i++) {
		std::cout << std::left << std::setw(3) << baseStats[i];
		if (i < GROWTHS_LENGTH) {
			std::cout << "(" << std::setw(2) << growthRates[i] << "%)";
		}
		std::cout << "|";
	}

	for (int i = 0; i < RANKS_LENGTH; i++) {
		if (weaponRanks[i] > 0) {
			if (counter != 0) {
				std::cout << "/";
			}
			std::cout << rankNames[i] << "(" << wpnRank(i) << ")";
			counter++;
		}
	}

	std::cout << std::endl;
}

char Stats::wpnRank(int idx) {
	char temp;

	if (weaponRanks[idx] > 250) {
		temp = 'S';
	}
	else if (weaponRanks[idx] > 180) {
		temp = 'A';
	}
	else if (weaponRanks[idx] > 120) {
		temp = 'B';
	}
	else if (weaponRanks[idx] > 70) {
		temp = 'C';
	}
	else if (weaponRanks[idx] > 30) {
		temp = 'D';
	}
	else if (weaponRanks[idx] > 0) {
		temp = 'E';
	}
	else {
		temp = '-';
	}

	return temp;
}