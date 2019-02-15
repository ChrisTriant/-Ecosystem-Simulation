#include<iostream>
#include"Tile.h"


class Ecosystem {
private:
	Tile* **terrain ;
	int terrain_size;
	const int hill_number = 2;
	int waterT;
	int hillT;
	int valleyT;
public:
	Ecosystem(int);
	void print_Eco();
	void GenerateRiver();
	void GenerateLake();
	void GenerateHills();
	void GenerateMeadow();
	void CountElements();
	void PlacePlants();
};
