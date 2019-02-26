#include<iostream>
#include<vector>
#include"Animals.h"

class Tile {
private:
	char landscape;
	std::vector<Animal*> animals;
	int animalCount;
	Plant* plant;
public:
	Tile(char c);
	char get_land();
	void addPlant(Plant* newplant);
	Plant* getPlant();
	void addAnimal(Animal* newanimal);
	Animal* getAnimal(int);
	void AnimalEating();
	void AnimalMovement();
	void CheckDeadEntities();
	void CheckHunger();
	void removeAnimal(int);
};
