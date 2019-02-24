#include"Tile.h"

Tile::Tile(char c)
{
	landscape = c;
	animalCount = 0;
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
	animalCount++;
}

Animal* Tile::getAnimal(int i)
{
	if(i <= (animalCount-1)) return animals[i];
	else return NULL;
}

void Tile::AnimalEating()
{
}



void Tile::AnimalMovement()
{
}

void Tile::CheckDeadEntities()
{// anything dead in tile gets deleted
	std::vector<Animal*>::iterator it;
	for (int i = 0; i < animals.size(); i++) {
		it =animals.begin();
		if (animals.at(i) != NULL && !(animals.at(i)->isalive())) {
			animals.erase(it);
			it--;
		}
		it++;
	}

	if (plant != NULL)
	{
		if (!plant->isAlive())
		{
			delete plant;
			plant = NULL;
		}
	}
}

void Tile::CheckHunger()
{
	int k = 1;
	Animal* animal = getAnimal(k);
	while (animal != NULL)
	{
		if (animal->getEatenFood() == 0)
		{
			animal->incEatCount();
		}
		if ((animal->getEatenFood()) >= 10)
		{
			animal->Die();
		}
		k++;
		animal = getAnimal(k);
	}
}
