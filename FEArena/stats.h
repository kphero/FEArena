#ifndef STATS_H
#define STATS_H

#include <iostream>

#define STATS_LENGTH 7
#define OTHER_STATS_LENGTH 3

class Stats {
	int currentHP;
	int baseStats[STATS_LENGTH];
	int otherStats[OTHER_STATS_LENGTH];
	int growthRates[STATS_LENGTH];
};

#endif
