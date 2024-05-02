#include "stats.h"

// Methods
Stats::Stats() {
	currentHP = 0;
	totalGrowths = 0;
	totalStats = 0;
}

Stats::Stats(int b[], int g[], int w[]) {
	currentHP = b[0];
	totalGrowths = 0;
	totalStats = 0;

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

int Stats::getTotalStats() {
	return totalStats;
}

int Stats::getTotalGrowths() {
	return totalGrowths;
}

// Getter for base stats based on provided index
int Stats::getStats(int idx) {
	int temp;

	switch (idx) {
	case (0):
		temp = baseStats[0];
		break;
	case (1):
		temp = baseStats[1];
		break;
	case (2):
		temp = baseStats[2];
		break;
	case (3):
		temp = baseStats[3];
		break;
	case (4):
		temp = baseStats[4];
		break;
	case (5):
		temp = baseStats[5];
		break;
	case (6):
		temp = baseStats[6];
		break;
	case (7):
		temp = currentHP;
		break;
	default:
		temp = -1;
		break;
	}

	return temp;
}

// Assignment overload
Stats& Stats::operator=(Stats& other) {
	this->currentHP = other.currentHP;
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

// Display
void Stats::display() {
	std::cout << "|------ STATS -------|" << std::endl;
	for (int i = 0; i < STATS_LENGTH; i++) {
		// Display stat
		std::cout << "| " << std::setw(4) << statCall(i) << ": [";
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
		std::cout << wpnCall(i) << ": " << wpnRank(i) << " | ";
	}
	
	std::cout << "\n|----------------------------------|\n"  << std::endl;
}

void Stats::lineDisplay() {
	std::cout << "Weapon Type(s): ";
	for (int i = 0; i < RANKS_LENGTH; i++) {
		if (weaponRanks[i] > 0) {
			std::cout << wpnCall(i) << ", ";
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < STATS_LENGTH; i++) {
		std::cout << statCall(i) << ": " << baseStats[i] << ", ";
	}
	std::cout << std::endl;
	for (int i = 0; i < GROWTHS_LENGTH; i++) {
		std::cout << statCall(i) << ": " << growthRates[i] << ", ";
	}
	std::cout << std::endl;
}

std::string Stats::statCall(int idx) {
	std::string temp;

	switch (idx) {
	case (0):
		temp.assign("HP");
		break;
	case (1):
		temp.assign("S/M");
		break;
	case (2):
		temp.assign("SKL");
		break;
	case (3):
		temp.assign("SPD");
		break;
	case (4):
		temp.assign("LUK");
		break;
	case (5):
		temp.assign("DEF");
		break;
	case (6):
		temp.assign("RES");
		break;
	case (7):
		temp.assign("CON");
		break;
	}

	return temp;
}

std::string Stats::wpnCall(int idx) {
	std::string temp;

	switch (idx) {
	case (0):
		temp.assign("Swd");
		break;
	case (1):
		temp.assign("Lnc");
		break;
	case (2):
		temp.assign("Axe");
		break;
	case (3):
		temp.assign("Bow");
		break;
	case (4):
		temp.assign("Anm");
		break;
	case (5):
		temp.assign("Lgt");
		break;
	case (6):
		temp.assign("Drk");
		break;
	case (7):
		temp.assign("Stf");
		break;
	}

	return temp;
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