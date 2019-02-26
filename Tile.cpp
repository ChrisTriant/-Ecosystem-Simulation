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
	if (i <= (animalCount - 1)) return animals[i];
	else return NULL;
}

void Tile::AnimalEating()
{
	for (unsigned int i = 0; i < animalCount; i++) {
		if (animals.at(i) != NULL && animals.at(i)->isalive()) 
		{

				if (animals[i]->getToken() == 'H' && plant != NULL)
				{
					animals[i]->Eat(plant);
				}
				if (animals[i]->getToken() == 'C')
				{ 
					int j = i+1;
					if (j >= animalCount) j = 0;
					while (animals.at(j) != NULL && animals.at(j)->isalive())
					{
						if (j == i && !(j+1)>=animalCount)j++;
						if (animals[i]->getHunger() > 8)
						{
							animals[i]->Eat(animals.at(j));
						}
						else if (animals.at(j)->getToken() == 'H')	animals[i]->Eat(animals.at(j));
						j++;
						if (j >= animalCount) break;
					}
					
				}
				break;
		}
	}
}



void Tile::AnimalMovement()
{

}

void Tile::CheckDeadEntities()
{// anything dead in tile gets deleted
	std::vector<Animal*>::iterator it;
	for (unsigned int i = 0; i < animalCount; i++) {
		if (animals.at(i) != NULL && !(animals.at(i)->isalive())) {
			animals.erase(animals.begin() + i);
			std::cout << "I'm dead" << std::endl;
			animalCount--;
			i--;
		}
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
			animal->incHunger();
		}
		if ((animal->getHunger()) >= 10)
		{
			animal->Die();
		}
		k++;
		animal = getAnimal(k);
	}
}

void Tile::removeAnimal(int i)
{
	animals[i] = NULL;
	animals.erase(animals.begin() + i);
	animalCount--;
}