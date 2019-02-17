#include<iostream>
#include<vector>
#include"Animals.h"
#include"Plants.h"
class Tile {
private:
	char landscape;
	std::vector<Animal*> animals;
	Plant* plant;
public:
	Tile(char c);
	char get_land();
	void addPlant(Plant* newplant);
	Plant* getPlant();
	void addAnimal(Animal* newanimal);
	void AnimalEating();
};
