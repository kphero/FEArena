#ifndef STATS_H
#define STATS_H

#include <iostream>

#define STATS_LENGTH 7
#define OTHER_STATS_LENGTH 3

class Stats {
public:
	int currentHP;
	int baseStats[STATS_LENGTH];
	int otherStats[OTHER_STATS_LENGTH];
	int growthRates[STATS_LENGTH];
	int totalStats;
	int totalGrowths;
	int getTotalStats() {
		return totalStats;
	}

	int getTotalGrowths() {
		return totalGrowths;
	}

	// Getter for base stats based on provided index
	int getStats(int idx) {
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
};

#endif
