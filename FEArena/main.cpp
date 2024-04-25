#include "stats.h"

// TODO: CSV files for characters, classes, items to be loaded in at start

int main() {
	// Test stats
	int stats1[] = { 16, 4, 8, 9, 0, 3, 1, 5 };
	int stats2[] = { 18, 6, 6, 7, 0, 6, 0, 8 };

	int growths1[] = { 85, 45, 40, 45, 45, 15, 20};
	int growths2[] = { 90, 50, 40, 40, 40, 20, 15};

	int ranks1[] = { 20, 0, 0, 0, 0, 0, 0, 0 };
	int ranks2[] = { 0, 60, 0, 0, 0, 0, 0, 0 };

	Stats char1 = Stats(stats1, growths1, ranks1);
	Stats char2 = Stats(stats2, growths2, ranks2);

	// Display
	char1.display();
	char2.display();

	// Swap
	char1 = char2;
	char1.display();


	return 0;
}