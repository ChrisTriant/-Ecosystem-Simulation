#include<iostream>
#include<vector>
#include"Animals.h"

class Tile {
private:
	char landscape;
	std::vector<Animal*> animals;
	int animalCount;
	int herbCount;
	int carnCount;
	Plant* plant;
public:
	Tile();
	~Tile();
	char get_land();
	void set_land(char l);
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
