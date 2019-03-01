#include<iostream>
#include"Ecosystem.h"
using namespace std;
int main(void) {
	int terrain_size=0;
	int season=0;
	int simDuration=0;
	// sim starts at day one of selected season
	do {
		cout << "Enter terrain_size (At least 10)" << endl;
		cin >> terrain_size;
	} while (terrain_size < 10);
	do {
		cout << "Select Season:" << endl;
		cout << "1. Winter" << endl;
		cout << "2. Spring" << endl;
		cout << "3. Summer" << endl;
		cout << "4. Fall" << endl;
		cin >> season;
	} while (season <= 0 || season >= 5);
	do {
		cout << "Enter sim duration in days:" << endl;
		cin >> simDuration;
	} while (simDuration <= 0);
	Ecosystem eco(terrain_size, season, simDuration);
	eco.RunEcosystem();
	cout << endl;
	return 0;
}