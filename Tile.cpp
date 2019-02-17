#include"Tile.h"

Tile::Tile(char c)
{
	landscape = c;
}

char Tile::get_land()
{
	return landscape;
}
void Tile::addPlant(Plant* newplant)
{
	plant = newplant;
}

Plant* Tile::getPlant()
{
	return plant;
}

void Tile::addAnimal(Animal* newanimal) {
	animals.push_back(newanimal);
}