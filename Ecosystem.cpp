#include"Ecosystem.h"
#include<ctime>
#include<Windows.h>
using namespace std;


Ecosystem::Ecosystem(int t, int s, int sd) :terrain_size(t), season(s), simDuration(sd) {
	terrain = new Tile**[terrain_size];
	waterT = 0;
	hillT = 0;
	valleyT = 0;
	hourOfDay = 0;
	dayOfYear = 1;
	timesSeasonChanged = 1;

	for (int i = 0; i < terrain_size; i++) {
			terrain[i] = new Tile*[terrain_size-1];
	}
	for (int i = 0; i < terrain_size; i++) {
		for (int j=0; j < terrain_size; j++) {
			terrain[i][j] = NULL;
		}
	}
	GenerateRiver();
	GenerateLake();
	GenerateHills();
	GenerateMeadow();
	CountElements();
	PlacePlants();
	PlaceAnimals();
	ApplySeason();
}

void Ecosystem::print_Eco() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < terrain_size; i++) {
		for (int s=0; s < terrain_size; s++) {
			cout << "-----";
		}
		cout << endl;
		for (int j = 0; j < terrain_size; j++) {
			if (terrain[i][j] != NULL) {
				cout << "| " ;
				if (terrain[i][j]->get_land() == '#') {
					SetConsoleTextAttribute(hConsole, 1);
					cout << terrain[i][j]->get_land();
					SetConsoleTextAttribute(hConsole, 7);
					cout << " |";
				}
				else if(terrain[i][j]->get_land() == '\"'){
					SetConsoleTextAttribute(hConsole, 2);
					cout << terrain[i][j]->get_land();
					SetConsoleTextAttribute(hConsole, 7);
					cout<< " |";
				}
				else if (terrain[i][j]->get_land() == '^') {
					SetConsoleTextAttribute(hConsole, 6);
					cout << terrain[i][j]->get_land();
					SetConsoleTextAttribute(hConsole, 7);
					cout << " |";
				}
			}
			
			
		}
		cout << endl;
	}
	for (int s = 0; s < terrain_size; s++) {
		cout << "-----";
	}
}

void Ecosystem::GenerateRiver() {
	srand(time(NULL));
	int r = rand() % (terrain_size - 9) + 5;
	for (int i = 0; i < terrain_size; i++) {
		terrain[i][r] = new Tile('#');
		int t = rand() % (10) + 1;
		if (t < 4) {				//30% chance to move
			t = rand() % 4 + 1;
			switch (t){
			case 1:										//move once to the right
				if (r + 1 < terrain_size) {
					terrain[i][r + 1] = new Tile('#');
					r++;
				}
				break;
			case 2:										//move twice to the right
				if (r + 1 < terrain_size) {					
					terrain[i][r + 1] = new Tile('#');
					r++;
				}
				if (r + 1 < terrain_size) {					
					terrain[i][r + 1] = new Tile('#');
					r++;
				}
				break;
			case 3:											//move once to the left
				if (r -1 >= 0) {
					terrain[i][r - 1] = new Tile('#');
					r--;
				}
				break;
			case 4:											//move twice to the left
				if (r - 1 >= 0) {
					terrain[i][r - 1] = new Tile('#');
					r--;
				}
				if (r - 1 >= 0) {
					terrain[i][r - 1] = new Tile('#');
					r--;
				}
				break;
			}

		}
	}
	

}
void Ecosystem::GenerateLake()
{
	srand(time(NULL));
	int lakesize = rand() % (terrain_size / 3)+2 ;
	int x = rand() % (terrain_size - lakesize);
	int y = rand() % (terrain_size - lakesize);
	for (int i=x; i < x+lakesize; i++) {
		for (int j=y; j < y+lakesize; j++) {
			terrain[i][j] = new Tile('#');
		}
	}
}

void Ecosystem::GenerateHills()
{
	srand(time(NULL));
	for (int i = 0; i < hill_number; i++)
	{
		int hillsize = rand() % 3 + 2;
		int x = rand() % (terrain_size - hillsize);
		int y = rand() % (terrain_size - hillsize);
		for (int i = x; i < x + hillsize; i++) {
			for (int j = y; j < y + hillsize; j++) {
				if (terrain[i][j] == NULL) terrain[i][j] = new Tile('^');
			}
		}
	}
}

void Ecosystem::GenerateMeadow()
{
	for (int i = 0; i < terrain_size; i++) {
		for (int j = 0; j < terrain_size; j++) {
			if (terrain[i][j] == NULL) {
				terrain[i][j] = new Tile('\"');
			}
		}
	}
}

void Ecosystem::CountElements() {
	for (int i = 0; i < terrain_size; i++) {
		for (int j = 0; j < terrain_size; j++) {
			if (terrain[i][j]->get_land() == '#') {
				waterT++;
			}
			else if (terrain[i][j]->get_land() == '^') {
				hillT++;
			}
			else {
				valleyT++;
			}
		}
	}
}

void Ecosystem::PlacePlants()
{
	srand(time(NULL));
	for (int i = 0; i < terrain_size; i++)
	{
		for (int j = 0; j < terrain_size; j++)
		{
			int prob = rand() % 100 + 1;
			if (prob < 50)
			{
				if (terrain[i][j]->get_land() == '#')
				{    //algae
					terrain[i][j]->addPlant(new Algae(i,j));
					cout << "Algae generated in tile " << i << "-" << j << endl;
				}
				else if (terrain[i][j]->get_land() == '^')
				{ // maple, pine
					int morp = rand() % 1;
					if (morp)
					{
						terrain[i][j]->addPlant(new Maple(i,j));
						cout << "Maple generated in tile " << i << "-" << j << endl;
					}
					else
					{
						terrain[i][j]->addPlant(new Pine(i,j));
						cout << "Pine generated in tile " << i << "-" << j << endl;
					}
				}
				else
				{ //grass, oak, maple
					int grom = rand() % 3 + 1;
					switch (grom) {
					case 1:
						terrain[i][j]->addPlant(new Grass(i,j));
						cout << "Grass generated in tile " << i << "-" << j << endl;
						break;
					case 2:
						terrain[i][j]->addPlant(new Oak(i,j));
						cout << "Oak generated in tile " << i << "-" << j << endl;
						break;
					case 3:
						terrain[i][j]->addPlant(new Maple(i,j));
						cout << "Maple generated in tile " << i << "-" << j << endl;
						break;
					default:
						break;
					}
				}
			}
		}
	}
}


void Ecosystem::PlaceAnimals()
{
	srand(time(NULL));
	for (int i = 0; i < terrain_size; i++)
	{
		for (int j = 0; j < terrain_size; j++)
		{
			int prob = rand() % 100 + 1;
			if (prob < 50)
			{
				int amount = rand() % 5 + 1;
				if (terrain[i][j]->get_land() == '#')
				{	
					for (int a = 0; a < amount; a++) {
						terrain[i][j]->addAnimal(new Salmon(i, j));
						cout << "Salmon generated in tile " << i << "-" << j << endl;
					}
				}
				else if (terrain[i][j]->get_land() == '^')
				{    // wolf, Bear
					for (int a = 0; a < amount; a++) {
						int anim = rand() % 2 ;
						if (anim==1)
						{
							terrain[i][j]->addAnimal(new Wolf(i, j));
							cout << "Wolf generated in tile " << i << "-" << j << endl;
						}
						else
						{
							terrain[i][j]->addAnimal(new Bear(i, j));
							cout << "Bear generated in tile " << i << "-" << j << endl;
						}
					}
				}
				else
				{    //Wolf, Fox
					for (int a = 0; a < amount; a++) {
						int anim = rand() % 4 + 1;
						switch (anim) {
						case 1:
							terrain[i][j]->addAnimal(new Wolf(i, j));
							cout << "Wolf generated in tile " << i << "-" << j << endl;
							break;
						case 2:
							terrain[i][j]->addAnimal(new Fox(i, j));
							cout << "Fox generated in tile " << i << "-" << j << endl;
							break;
						case 3:
							terrain[i][j]->addAnimal(new Rabbit(i, j));
							cout << "Rabbit generated in tile " << i << "-" << j << endl;
							break;
						case 4:
							terrain[i][j]->addAnimal(new Deer(i, j));
							cout << "Deer generated in tile " << i << "-" << j << endl;
							break;
						case 5:
							terrain[i][j]->addAnimal(new GroundHog(i, j));
							cout << "Groundhog generated in tile " << i << "-" << j << endl;
							break;
						default:
							break;
						}
					}
				}
			}
		}
	}
}


void Ecosystem::RunEcosystem()
{
	while (hourOfDay < 25)
	{
		if (dayOfYear == 90*timesSeasonChanged)
		{
			season++;
			if (season >= 5) season = 1;
			ApplySeason();
			timesSeasonChanged++;
		}

		for (int i = 0; i < terrain_size; i++) {
			for (int j = 0; j < terrain_size; j++) {
				terrain[i][j]->AnimalMovement();
				terrain[i][j]->AnimalEating();
				/* carnivore eats another carnivore only after 8 days without food
				** if herbivore eats enough -> does not eat for 7 days
				*/
				terrain[i][j]->CheckDeadEntities();
			}
		}

		if (hourOfDay < 24)
		{
			hourOfDay++;
		}
		else
		{
			EndDay();

			if (dayOfYear >= simDuration) break; //sim is over
		}
		
	}

}

void Ecosystem::DailyReset()
{
	ResetHunger();
	
	if (dayOfYear%animal_growthPeriod == 0)
	{
		for (int i = 0; i < terrain_size; i++) {
			for (int j = 0; j < terrain_size; j++) {
				int k = 1;
				Animal* animal;
				while ( (animal = terrain[i][j]->getAnimal(k)) != NULL)
				{
					animal->Raise();
					k++;
				}
			}
		}
	}
	if (season!=4 && dayOfYear%plants_growthPeriod == 0)
	{
		for (int i = 0; i < terrain_size; i++) {
			for (int j = 0; j < terrain_size; j++) {
				Plant* tempPlant = terrain[i][j]->getPlant();
				if (tempPlant != NULL) {
					tempPlant->grow(season);
				}
			}
		}
	}
	dayOfYear++;
}

void Ecosystem::ApplySeason()
{
	switch (season)
	{
	case 1:								//winter
		plants_growthPeriod = 10;				
		animal_growthPeriod = 30;
		plants_breedingRepPeriod = 0;
		herbivors_breedingRepPeriod = 18;
		carnivore_breedingRepPeriod = 10;
		AnimalSleep();
		break;
	case 2:								//spring
		plants_growthPeriod = 5;
		animal_growthPeriod = 20;
		plants_breedingRepPeriod = 10;
		herbivors_breedingRepPeriod = 12;
		carnivore_breedingRepPeriod = 11;
		AnimalWake();
		break;
	case 3:							  //summer
		plants_growthPeriod = 10;
		animal_growthPeriod = 30;
		plants_breedingRepPeriod = 10;
		herbivors_breedingRepPeriod = 8;
		carnivore_breedingRepPeriod = 9;
		break;
	case 4:							//autumn
		plants_growthPeriod = 0;
		animal_growthPeriod = 15;
		plants_breedingRepPeriod = 20;
		herbivors_breedingRepPeriod = 5;
		carnivore_breedingRepPeriod = 9;
		break;
	default:
		break;
	}
}

void Ecosystem::ResetHunger()
{
	for (int i = 0; i < terrain_size; i++) {
		for (int j = 0; j < terrain_size; j++) {
			int k = 1;
			Animal* animal = terrain[i][j]->getAnimal(k);
			while (animal != NULL)
			{
				animal->setEatenFood(0);
				k++;
				animal = terrain[i][j]->getAnimal(k);
			}
		}
	}
}

void Ecosystem::PlantBreading(int i, int j)
{
	if(plants_breedingRepPeriod != 0)
	if (dayOfYear%plants_breedingRepPeriod == 0)
	{
		Plant* temP = terrain[i][j]->getPlant();
		if (temP != NULL)
		{
			srand(time(NULL));
			int prob = rand() % 100 + 1;
			if (prob <= temP->getBreedingProb(season))
			{
				Tile * tempTile = FindFreeTile(i, j);
				if (tempTile != NULL)
				{
					char token = temP->getToken();
					if (token == 'G')
						tempTile->addPlant(new Grass(i, j));
					else if ((token == 'A'))
						tempTile->addPlant(new Algae(i, j));
					else if ((token == 'O'))
						tempTile->addPlant(new Oak(i, j));
					else if ((token == 'P'))
						tempTile->addPlant(new Pine(i, j));
					else
						tempTile->addPlant(new Maple(i, j));
				}
			}
		}
	}
}

void Ecosystem::AnimalBreeding(int i ,int j)
{
	int k = 1;
	Animal* animal = terrain[i][j]->getAnimal(k);
	while (animal != NULL)
	{
		if (animal->isAdult()) //isAdult does nothing (returns false always)
		{
			if ((animal->getToken() == 'H') && (dayOfYear%herbivors_breedingRepPeriod == 0))
			{	// new instance of same type gets created at same tile

				GiveBirth(animal, i, j);
			}
			else if ((animal->getToken() == 'C') && (dayOfYear%carnivore_breedingRepPeriod == 0))
			{	// new instance of same type gets created at same tile

				GiveBirth(animal, i, j);
			}
		}

		k++;
		animal = terrain[i][j]->getAnimal(k);
	}
}

void Ecosystem::GiveBirth(Animal * animal, int i, int j)
{

	string name = animal->getName();

	if (name == "Bear")
	{
		terrain[i][j]->addAnimal(new Bear(i, j));
	}
	else if (name == "Salmon")
	{
		terrain[i][j]->addAnimal(new Salmon(i, j));
	}
	else if (name == "Deer")
	{
		terrain[i][j]->addAnimal(new Deer(i, j));
	}
	else if (name == "GroundHog")
	{
		terrain[i][j]->addAnimal(new GroundHog(i, j));
	}
	else if (name == "Wolf")
	{
		terrain[i][j]->addAnimal(new Wolf(i, j));
	}
	else if (name == "Fox")
	{
		terrain[i][j]->addAnimal(new Fox(i, j));
	}
	else
	{
		terrain[i][j]->addAnimal(new Rabbit(i, j));
	}
	cout << "animal created" << endl;
}

Tile * Ecosystem::FindFreeTile(int &i, int &j)
{
	if (terrain[i][j - 1]->getPlant() == NULL)
	{
		j--;
		return (terrain[i][j - 1]);
	}
	else if (terrain[i][j + 1]->getPlant() == NULL)
	{
		j++;
		return (terrain[i][j + 1]);
	}
	else if (terrain[i + 1][j]->getPlant() == NULL)
	{
		i++;
		return (terrain[i + 1][j]);
	}
	else if (terrain[i - 1][j]->getPlant() == NULL)
	{
		i--;
		return (terrain[i - 1][j]);
	}
	else
		return NULL;
}

void Ecosystem::AnimalSleep()
{
	for (int i = 0; i < terrain_size; i++) {
		for (int j = 0; j < terrain_size; j++) {
			int k = 1;
			Animal* animal;
			while ((animal = terrain[i][j]->getAnimal(k)) != NULL)
			{
				if (animal->CanHibernate())
				{
					animal->Hibernate();
				}
				k++;
			}
		}
	}
}

void Ecosystem::AnimalWake()
{
	for (int i = 0; i < terrain_size; i++) {
		for (int j = 0; j < terrain_size; j++) {
			int k = 1;
			Animal* animal;
			while ((animal = terrain[i][j]->getAnimal(k)) != NULL)
			{
				if (animal->CanHibernate())
				{
					animal->Wake();
				}
				k++;
			}
		}
	}
}

void Ecosystem::EndDay()
{
	hourOfDay = 0;
	for (int i = 0; i < terrain_size; i++) {
		for (int j = 0; j < terrain_size; j++) {
			terrain[i][j]->CheckHunger();
			terrain[i][j]->CheckDeadEntities();

			AnimalBreeding(i, j);
			PlantBreading(i, j);
		}
	}

	// apo ekfwnhsh:
	// epipleon, ta fyta anaplhrwnoun energeia kai pi8anws megalwnoun opws anafer8hke se prohgoumenh enothta <- wtf is this?

	
	DailyReset();	//that comes every cycle -> after 24 hours
}
