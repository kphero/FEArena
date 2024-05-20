#ifndef STATS_H
#define STATS_H

#include <iostream>
#include <iomanip>

#define STATS_LENGTH 8 // HP, STR/MAG, SKL, SPD, LUK, DEF, RES, CON
#define GROWTHS_LENGTH 7 // HP, STR/MAG, SKL, SPD, LUK, DEF, RES
#define RANKS_LENGTH 8 // Sword, Lance, Axe, Bow, Anima, Light, Dark, Staff

extern std::string statNames[STATS_LENGTH];
extern std::string statNamesLong[STATS_LENGTH];
extern std::string rankNames[RANKS_LENGTH];
extern std::string rankNamesLong[RANKS_LENGTH];

// WPN Rank Exp Breakpoints:
// E: 1
// D: 31
// C: 71
// B: 121
// A: 181
// S: 251

class Stats {
	// Bases
	int baseStats[STATS_LENGTH] = { 0,0,0,0,0,0,0,0 };
	int totalStats{};

	// Growths
	int growthRates[GROWTHS_LENGTH] = { 0,0,0,0,0,0,0 };
	int totalGrowths{};

	// Weapon Ranks
	int weaponRanks[RANKS_LENGTH] = { 0,0,0,0,0,0,0,0 };
public:
	// ******** CONSTRUCTORS ********* //
	Stats();
	Stats(int b[], int g[], int w[]);
	Stats(Stats& other);

	// ******** GETTERS ********* //
	int getTotalStats() const;
	int getTotalGrowths() const;
	int getStats(int idx) const;
	int getGrowths(int idx) const;
	int getRanks(int idx) const;


	// ******** SETTERS ********* //
	void addTotalStats(int n);
	void addTotalGrowths(int n);
	void addStats(int idx, int n);
	void addGrowths(int idx, int n);
	void addRanks(int idx, int n);

	// ******** OVERLOADS ********* //
	Stats& operator=(Stats& other);

	// ******** DISPLAY ********* //
	void display();
	void lineHeader();
	void lineDisplay();
	char wpnRank(int idx);

};

#endif
