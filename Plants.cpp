#include"Plants.h"
using namespace std;

Plant::Plant(char t, int s, int bp, int l, int lf,int x,int y) :token(t), illnessProb(s), life(l), lifeFactor(lf),x(x),y(y), breedingProb(bp) {
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
}

bool Plant::isAlive(){
	return life!=0;
}

int Plant::getSize()
{
	return 0;
}


bool Plant::isSick() {
	return sick;
}

void Plant::operate() 
{

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

int Plant::getIllnessProb(int)
{
	return illnessProb;
	//return illnessProb[season];
}

int Plant::getBreedingProb(int season)
{
	return breedingProb;
	//return breedingProb[season];
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

int Plant::getToken()
{
	return token;
}

std::string Plant::getName()
{
	return name;
}

/*##################################################*/
/*###################SEEDLESS######################*/

Seedless::Seedless(char t, int s, int bp, int l, int lf,int x,int y) :Plant(t, s, bp, l, lf,x,y) {

}




void Seedless::operate()
{
	if (isSick())
	{
		LoseLife(getLifeFac());
	}
	else
	{
		IncLife();
	}
}

/*##################################################*/
/*###################SEEDED######################*/

Seeded::Seeded(char t, int s, int bp, int l, int lf, int f, int sd, int sz,int x,int y) :Plant(t, s, bp, l, lf,x,y), foliage(f), seeds(sd), size(sz) {

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


void Seeded::operate()
{
	if (isSick())
	{
		LoseLife(getLifeFac());
		seeds -= (2 * getLifeFac());
		// na doume afto me to foliage kai to lifeFactor
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

	/*##################################################*/
	/*#####################GRASS/ALGAE########################*/
	Grass::Grass(int x,int y):Seedless('G', 15, 15, 5, 2,x,y)
	{
	}

	Algae::Algae(int x,int y):Seedless('A', 25, 25, 5, 2,x,y)
	{
	}

	/*##################################################*/

	/*#########################OAK/PINE/MAPLE######################*/
	Oak::Oak(int x,int y) : Seeded('O', 20, 20, 30, 15, 30, 15, 5,x,y)
	{
	}
	Maple::Maple(int x,int y) : Seeded('M', 5, 5, 20, 10, 20, 10, 2,x,y)
	{
	}
	Pine::Pine(int x,int y) : Seeded('P', 15, 15, 40, 20, 40, 20, 5,x,y)
	{
	}
