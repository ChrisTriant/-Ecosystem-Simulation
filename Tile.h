#include<iostream>
#include"Plants.h"
class Tile {
private:
	char landscape;
	//Animal List
	Plant* plant;
public:
	Tile(char c);
	char get_land();
	void addPlant(Plant* newplant);
	Plant* getPlant();
};
