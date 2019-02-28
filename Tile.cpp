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
	if (newanimal->getToken() == 'H')
	{
		herbCount++;
	}
	else
	{
		carnCount++;
	}
}

Animal* Tile::getAnimal(int i)
{
	if (i < animalCount) return animals[i];
	else return NULL;
}

void Tile::AnimalEating()
{
	for (unsigned int i = 0; i < animalCount; i++) {
		if (animals.at(i) != NULL && animals.at(i)->isalive() && !animals.at(i)->isHiber())
		{
			if (animals[i]->getName() == "Fox")
			{
				int x = 5;
			}
			if (animals[i]->getToken() == 'H' && plant != NULL)
			{
				animals[i]->Eat(plant);
			}
			if (animals[i]->getToken() == 'C')
			{
				int j = 0;
				//int j = i + 1;
				//if (j >= animalCount) j = 0;
				while (animals.at(j) != NULL && animals.at(j)->isalive())
				{
 					if (j == i && ((++j) >= animalCount)) break;

					if (animals[i]->getHunger() > 8)
					{
						if (animals.at(j)->isalive())
						if (animals[i]->Eat(animals.at(j)))
						{
							std::cout << animals.at(i)->getName() << " ate " << animals.at(j)->getName() << std::endl;
							break;
						}
					}
					else if (animals.at(j)->getToken() == 'H')
					{
						if (animals.at(j)->isalive())
						if (animals[i]->Eat(animals.at(j)))
						{
							std::cout << animals.at(i)->getName() << " ate " <<animals.at(j)->getName() <<  std::endl;
							break;
						}
					}
					j++;
					if (j >= animalCount) break;
				}

			}
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
			std::cout << animals.at(i)->getName() << " is dead" << std::endl;
			animals.erase(animals.begin() + i);
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
	int k = 0;
	Animal* animal = getAnimal(k);
	while (animal != NULL)
	{
		if (animal->isHiber()) {
			animal->setHungerCount(0);
			animal->incEatenFood(1);
			return;
		}
		if (animal->getEatenFood() == 0)
		{
			animal->incHunger();
		}
		if ((animal->getHunger()) >= 10)
		{
			animal->Die();
			std::cout << "I'm starving to death" << std::endl;
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