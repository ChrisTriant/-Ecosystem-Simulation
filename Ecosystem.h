#include<iostream>
#include<vector>
#include"Tile.h"


class Ecosystem {
private:
	Tile* **terrain ;
	int terrain_size;
public:
	Ecosystem(int);
	void print_Eco();
};
