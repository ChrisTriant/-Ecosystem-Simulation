#include"Ecosystem.h"
using namespace std;


Ecosystem::Ecosystem(int t) :terrain_size(t) {
	terrain = new Tile**[terrain_size];
	for (int i = 0; i < terrain_size; i++) {
			terrain[i] = new Tile*[terrain_size-1];
	}
	for (int i = 0; i < terrain_size; i++) {
		for (int j = 0; j < terrain_size; j++) {
			terrain[i][j] = new Tile();
		}
	}
}

void Ecosystem::print_Eco() {
	for (int i = 0; i < terrain_size; i++) {
		for (int s=0; s < terrain_size; s++) {
			cout << "-----";
		}
		cout << endl;
		for (int j = 0; j < terrain_size; j++) {
			if (terrain[i][j]->get_land() == '#') {
				cout << "| " << terrain[i][j]->get_land() << " |";
			}
		}
		cout << endl;
	}
	for (int s = 0; s < terrain_size; s++) {
		cout << "-----";
	}
}