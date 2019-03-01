#include"Plants.h"
#include<ctime>
#include<cstdlib>
using namespace std;

Plant::Plant(char t, int l, int lf, int x, int y) : token(t), life(l), lifeFactor(lf), x(x), y(y) {
	if (token == 'G') {
		name = "Grass";
	}
	else if (token == 'A') {
		name = "Algae";
	}
	else if (token == 'O') {
		name = "Oak";
	}
	else if (token == 'P') {
		name = "Pine";
	}
	else if (token == 'M') {
		name = "Maple";
	}
	srand(time(NULL));
	if (token == 'A' || token == 'G') {
		illnessProb[0] = rand() % 11 + 30;
		illnessProb[1] = rand() % 11 + 10;
		illnessProb[2] = rand() % 10 + 1;
		illnessProb[3] = rand() % 11 + 20;
		breedingProb[0] = 0;
		breedingProb[1] = rand() % 11 + 80;
		breedingProb[2] = rand() % 11 + 70;
		breedingProb[3] = rand() % 11 + 40;
	}
	else {
		illnessProb[0] = rand() % 11 + 40;
		illnessProb[1] = rand() % 11 + 20;
		illnessProb[2] = rand() % 11 + 10;
		illnessProb[3] = rand() % 11 + 30;
		breedingProb[0] = 0;
		breedingProb[1] = 100;
		breedingProb[2] = rand() % 11 + 80;
		breedingProb[3] = rand() % 11 + 50;
	}
}

Plant::~Plant()
{
}

bool Plant::isAlive() {
	return life != 0;
}

int Plant::getSize()
{
	return 0;
}


bool Plant::isSick() {
	return sick;
}


void Plant::grow(int season)
{
	srand(time(NULL));
	int prob = rand() % 100 + 1;
	if (prob <= getIllnessProb(season))
	{
		LoseLife(getLifeFac());
	}
	else
	{
		IncLife();
	}
}

int Plant::getIllnessProb(int season)
{
	//return illnessProb;
	return illnessProb[season];
}


int Plant::getBreedingProb(int season)
{
	//return breedingProb;
	return breedingProb[season];
}

bool Plant::isNewB()
{
	return newborn;
}

void Plant::setNewB(bool newb)
{
	newborn = newb;
}



void Plant::IncLife() {
	life += lifeFactor;
}
void Plant::LoseLife(int ehp) {
	life -= ehp;
}

void Plant::LoseLife()
{
	life--;
}

int Plant::getLife()
{
	return life;
}

int Plant::getLifeFac() {
	return lifeFactor;
}

char Plant::getToken()
{
	return token;
}

std::string Plant::getName()
{
	return name;
}

/*##################################################*/
/*###################SEEDLESS######################*/

Seedless::Seedless(char t, int s, int bp, int l, int lf, int x, int y) :Plant(t, l, lf, x, y) {

}

Seedless::~Seedless()
{
}



/*##################################################*/
/*###################SEEDED######################*/

Seeded::Seeded(char t, int s, int bp, int l, int lf, int f, int sd, int sz, int x, int y) :Plant(t, l, lf, x, y), foliage(f), seeds(sd), size(sz) {

}

Seeded::~Seeded()
{
}

void Seeded::LoseLife(int ehp)
{
	while ((ehp > 0) && isAlive())
	{
		if (seeds > 0)
		{
			LoseSeed();
		}
		else
		{
			LoseFoliage();
			Plant::LoseLife();
		}
		ehp--;
	}
}


void Seeded::grow(int season)
{
	srand(time(NULL));
	int prob = rand() % 100 + 1;
	if (prob <= getIllnessProb(season))
	{
		LoseLife(getLifeFac());
		seeds -= (2 * getLifeFac());
	}
	else
	{
		IncLife();
		seeds += (2 * getLifeFac());
	}
}

int Seeded::getSize()
{
	return size;
}

void Seeded::LoseSeed() {
	seeds--;
}
void Seeded::LoseFoliage() {
	foliage--;
}

int Seeded::getFoliage()
{
	return foliage;
}

int Seeded::getSeeds()
{
	return seeds;
}


/*##################################################*/
/*#####################GRASS/ALGAE########################*/
Grass::Grass(int x, int y) :Seedless('G', 15, 15, 5, 2, x, y)
{
}

Grass::~Grass()
{
}

Algae::Algae(int x, int y) : Seedless('A', 25, 25, 5, 2, x, y)
{
}

Algae::~Algae()
{
}

/*##################################################*/

/*#########################OAK/PINE/MAPLE######################*/
Oak::Oak(int x, int y) : Seeded('O', 20, 20, 30, 15, 30, 15, 5, x, y)
{
}
Oak::~Oak()
{
}
Maple::Maple(int x, int y) : Seeded('M', 5, 5, 20, 10, 20, 10, 2, x, y)
{
}
Maple::~Maple()
{
}
Pine::Pine(int x, int y) : Seeded('P', 15, 15, 40, 20, 40, 20, 5, x, y)
{
}

Pine::~Pine()
{
}
