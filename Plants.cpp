#include"Plants.h"
using namespace std;

Plant::Plant(char t, int s, int l, int lf) :token(t), illnessProb(s), life(l), lifeFactor(lf) {
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

bool Plant::isSick() {
	return sick;
}

void Plant::operate() {}
void Plant::breed() {

}

void Plant::IncLife() {
	life += lifeFactor;
}
void Plant::LoseLife(int ehp) {
	life -= ehp;
}

int Plant::getLifeFac() {
	return lifeFactor;
}

/*##################################################*/
/*###################SEEDLESS######################*/

Seedless::Seedless(char t, int s, int l, int lf) :Plant(t, s, l, lf) {

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
	srand(time(NULL));
	int prob = rand() % 100 + 1;
	//if (prob <= breedingProb[season] && (!isSick()))
	//{
	//breed();
}

/*##################################################*/
/*###################SEEDED######################*/

Seeded::Seeded(char t, int s, int l, int lf, int f, int sd, int sz) :Plant(t, s, l, lf), foliage(f), seeds(sd), size(sz) {

}

void Seeded::GotEaten(int ehp)
{
	while ((ehp > 0) && isAlive()) // ti tha geinei an to poso einai emgalitero apo seeds?
	{
		if (seeds > 0)
		{
			LoseSeed();
		}
		else
		{
			LoseFoliage();
			LoseLife(1);
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
	srand(time(NULL));
	int prob = rand() % 100 + 1;
	/*    if (prob <= breedingProb[season] && (!isSick()))
		{
			breed();
		} */
}

	void Seeded::LoseSeed() {
		seeds--;
	}
	void Seeded::LoseFoliage() {
		foliage--;
	}

	/*##################################################*/
	/*#####################GRASS/ALGAE########################*/
	Grass::Grass():Seedless('G', 15, 5, 2)
	{
	}

	Algae::Algae():Seedless('A', 25, 5, 2)
	{
	}

	/*##################################################*/

	/*#########################OAK/PINE/MAPLE######################*/
	Oak::Oak() : Seeded('O', 20, 30, 15, 30, 15, 5)
	{
	}
	Maple::Maple() : Seeded('M', 5, 20, 10, 20, 10, 2)
	{
	}
	Pine::Pine() : Seeded('P', 15, 40, 20, 40, 20, 5)
	{
	}
