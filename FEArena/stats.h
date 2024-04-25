#ifndef STATS_H
#define STATS_H

#include <iostream>

#define STATS_LENGTH 8 // HP, STR/MAG, SKL, SPD, LUK, DEF, RES, CON
#define GROWTHS_LENGTH 7 // HP, STR/MAG, SKL, SPD, LUK, DEF, RES
#define RANKS_LENGTH 8 // Sword, Lance, Axe, Bow, Anima, Light, Dark, Staff

// WPN Rank Exp Breakpoints:
// E: 1
// D: 31
// C: 71
// B: 121
// A: 181
// S: 251

class Stats {
public:
	// Bases
	int currentHP;
	int baseStats[STATS_LENGTH] = { 0,0,0,0,0,0,0,0 };
	int totalStats;

	// Growths
	int growthRates[GROWTHS_LENGTH] = { 0,0,0,0,0,0,0 };
	int totalGrowths;

	// Weapon Ranks
	int weaponRanks[RANKS_LENGTH] = { 0,0,0,0,0,0,0,0 };

	// ******** Methods ********* //
	Stats();
	Stats(int b[], int g[], int w[]);

	// Might be uneeded
	int getTotalStats();
	int getTotalGrowths();

	// Getter for base stats based on provided index
	int getStats(int idx);

	// Assignment overload
	Stats& operator=(Stats& other);

	// Display
	void display();
	// Determine through idx the name of stat
	std::string statCall(int idx);
	// Determine through idx and exp the rank of Wpn
	std::string wpnCall(int idx);
	char wpnRank(int idx);

};

#endif
