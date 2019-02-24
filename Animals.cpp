#include"Animals.h"

using namespace std;

Animal::Animal(int s, int eC, int sp,string name,int x,int y,bool hib, char tok) :size(s), eatCount(eC), speed(sp),name(name),x(x),y(y),Hibernates(hib), isAlive(true), token(tok) {
}

void Animal::Move()
{
}

void Animal::Eat()
{
}

void Animal::Raise(int s, int smax, int sp, int spmax, int ec, int ecmax)
{
	while (s > 0 && size < smax)
	{
		size++;
		s--;
	}
	while (sp > 0 && speed < spmax)
	{
		speed++;
		sp--;
	}
	while (ec > 0 && eatCount < ecmax)
	{
		eatCount++;
		ec--;
	}
}

int Animal::getSize()
{
	return size;
}

string Animal::getName()
{
	return name;
}

int Animal::getSpeed()
{
	return speed;
}

int Animal::getEatenFood()
{
	return eatenFood;
}

void Animal::incEatenFood(int i)
{
	eatenFood += i;
}

void Animal::setEatenFood(int ammount)
{
eatenFood = ammount;
}

void Animal::incEatCount()
{
	eatCount++;
}

int Animal::getEatCount()
{
	return eatCount;
}

void Animal::setHungerCount(int temp)
{
	hungerCount = temp;
}

void Animal::Die()
{
	isAlive = false;
}

bool Animal::isalive()
{
	return isAlive;
}

char Animal::getToken()
{
	return token;
}

bool Animal::CanHibernate()
{
	return Hibernates;
}

bool Animal::isAdult()
{
	return false;
}

void Animal::Hibernate()
{
	inHibernation = true;
}

void Animal::Wake()
{
	inHibernation = false;
}

/*########################################*/

/*#############HERBIVORS##################*/
Herbivor::Herbivor(int s, int sp, int nf, bool cc, int eC, string name, int x, int y, bool hib) :Animal(s, eC, sp, name, x, y, hib, 'H'), canClimb(cc), neededFood(nf)
{
}

void Herbivor::Eat(Plant * plant)
{
}

void Herbivor::Eat(Animal * animal)
{
	cout << "im tired of being a vegan\n";
}

void Herbivor::Raise(int s, int smax, int sp, int spmax, int ec, int ecmax, int nf, int nfmax)
{
		Animal::Raise(s, smax, sp, spmax, ec, ecmax);
		while (nf > 0 && neededFood < nfmax)
		{
			neededFood++;
			nf--;
		}
}

bool Herbivor::getClimb()
{
	return canClimb;
}

int Herbivor::getNeededFood()
{
	return neededFood;
}

/*#############DEER##################*/
Deer::Deer(int x, int y) :Herbivor(2, 4, 4, false, 2, "Deer", x, y, false)
{

}

void Deer::Eat(Plant * plant)
{
	if (plant == NULL || !(plant->isAlive())) {
		cout << "There is no plant in this tile\n";
		return;
	}
	if (getEatenFood() == getNeededFood()) {
		cout << "Deer is no longer hungry\n";
		return;
	}
	if (getSize()+4>plant->getSize()) {
	
			if (getEatCount() < plant->getLife()) {
				incEatenFood(getEatCount());
				cout << "Deer ate " << plant->getName() << endl;
				plant->LoseLife(getEatCount());
			}
			else {
				incEatenFood(plant->getLife());
				cout << "Deer ate " << plant->getName() << endl;
				plant->LoseLife(plant->getLife());
			}
			if (getEatenFood() == getNeededFood()) {
				cout << "Deer is no longer hungry\n";
				setHungerCount(0);
			}
	}
	
}

/*#############RABBIT##################*/


Rabbit::Rabbit(int x, int y) : Herbivor(1, 2, 2,false, 1,"Rabbit" ,x, y,false) {

}

void Rabbit::Eat(Plant * plant)
{
	if (plant == NULL || !(plant->isAlive())) {
		cout << "There is no plant in this tile\n";
		return;
	}

	if (getEatenFood() == getNeededFood()) {
		cout << "Rabbit is no longer hungry\n";
		return;
	}

	if (plant->getToken() == 'A') {
		cout << "Rabbit can't eat algae\n";
		return;
	}
	if (getSize() >= plant->getSize()) {
		if (getEatCount() < plant->getLife()) {
			incEatenFood(getEatCount());
			plant->LoseLife(getEatCount());
		}
		else {
			incEatenFood(plant->getLife());
			plant->LoseLife(plant->getLife());
		}
		if (getEatenFood() == getNeededFood()) {
			cout << "Rabbit is no longer hungry\n";
			setHungerCount(0);
		}
	}
}
/*#############GROUNDHOG##################*/

GroundHog::GroundHog(int x, int y):Herbivor(2,3,3,false,1,"Groundhog",x,y,true)
{
}

void GroundHog::Eat(Plant * plant)
{
	if (plant == NULL || !(plant->isAlive())) {
		cout << "There is no plant in this tile\n";
		return;
	}
	if (getEatenFood() == getNeededFood()) {
		cout << "Groundhog is no longer hungry\n";
		return;
	}
	if (plant->getToken() == 'A') {
		cout << "Groundhog can't eat algae\n";
		return ;
	}
	if (!getClimb()) {
		if (getSize() >= plant->getSize()) {
			if (getEatCount() < plant->getLife()) {
				incEatenFood(getEatCount());
				plant->LoseLife(getEatCount());
			}
			else {
				incEatenFood(plant->getLife());
				plant->LoseLife(plant->getLife());
			}
			if (getEatenFood() == getNeededFood()) {
				cout << "Groundhog is no longer hungry\n";
				setHungerCount(0);
			}
		}
	}
	else {
		if (getSize()* 3 >= plant->getSize()) {
				if (getEatCount() < plant->getLife()) {
					incEatenFood(getEatCount());
					plant->LoseLife(getEatCount());
				}
				else {
					incEatenFood(plant->getLife());
					plant->LoseLife(plant->getLife());
				}
				if (getEatenFood() == getNeededFood()) {
					cout << "Groundhog is no longer hungry\n";
					setHungerCount(0);
				}
		}
	}
	
}

/*#############SALMON##################*/

Salmon::Salmon(int x, int y):Herbivor(1,5,1,false,1,"Salmon",x,y,false)
{
}

void Salmon::Eat(Plant * plant)
{
	if (plant == NULL || !(plant->isAlive())) {
		cout << "There is no plant in this tile\n";
		return;
	}
	if (getEatenFood() == getNeededFood()) {
		cout << "Salmon is no longer hungry\n";
		return;
	}
	if (getEatCount() < plant->getLife()) {
		incEatenFood(getEatCount());
		plant->LoseLife(getEatCount());
		if (getEatenFood() == getNeededFood()) {
			cout << "Salmon is no longer hungry\n";
			setHungerCount(0);
		}
	}
	else {
		incEatenFood(plant->getLife());
		plant->LoseLife(plant->getLife());
		if (getEatenFood() == getNeededFood()) {
			cout << "Salmon is no longer hungry\n";
			setHungerCount(0);
		}
	}
	
}


// constructors

/* ######## Carnivore ######### */
Carnivore::Carnivore(int s, int eC, int sp, int a, int d, std::string n, int x, int y,bool hib) : Animal(s, eC, sp, n, x, y,hib,'C'), attack(a), defence(d) {

}

void Carnivore::Eat(Animal* animal)
{

}

int Carnivore::getDefence()
{
	return defence;
}

int Carnivore::getAttack()
{
	return attack;
}



/* ####### FOX ####### */

Fox::Fox(int x, int y) : Carnivore(1, 2, 1, 1, 1, "Fox", x, y,false) {

}

void Fox::Eat(Animal* animal) {
	string enemyName = animal->getName();
	char enemyToken = animal->getToken();
	int enemySize = animal->getSize();
	int enemySpeed = animal->getSpeed();
	int enemyDefence = ((Carnivore*)animal)->getDefence();
	int ownSize = getSize();
	int ownSpeed = getSpeed();
	int ownAttack = getAttack();
	
	if (enemyToken == 'H')  // if is herbivor
	{
		if ((ownSize >= enemySize) && (ownSpeed > enemySpeed))
		{
			if (enemyName != "Salmon")
			{
				setHungerCount(0);
				animal->Die();
			}
		}
	}
	else
	{
		if (ownSize > enemySize)
		{
			setHungerCount(0);
			animal->Die();
		}
		else if (ownSize == enemySize)
		{
			if (ownAttack > enemyDefence)
			{
				setHungerCount(0);
				animal->Die();
			}
		}
	}
}

/* ###### WOLF ####### */

Wolf::Wolf(int x, int y) : Carnivore(1, 2, 2, 2, 2, "Wolf", x, y,false) {

}

void Wolf::Eat(Animal* animal) {
	string enemyName = animal->getName();
	char enemyToken = animal->getToken();
	int enemySize = animal->getSize();
	int enemySpeed = animal->getSpeed();
	int enemyDefence = ((Carnivore*)animal)->getDefence();
	int ownSize = getSize();
	int ownSpeed = getSpeed();
	int ownAttack = getAttack();

	if (enemyToken == 'H')  // if is herbivor
	{
		if ((ownSize >= enemySize) && (ownSpeed > enemySpeed))
		{
			if (enemyName != "Salmon")
			{
				setHungerCount(0);
				animal->Die();
			}
		}
	}
	else
	{
		if (ownSize > enemySize)
		{
			setHungerCount(0);
			animal->Die();
		}
		else if (ownSize == enemySize)
		{
			if (ownAttack > enemyDefence)
			{
				setHungerCount(0);
				animal->Die();
			}
		}
	}
}

/* ###### Bear ####### */

Bear::Bear(int x, int y) : Carnivore(3, 5, 4, 6, 6, "Bear", x, y,true) {

}

void Bear::Eat(Animal* animal) {
	string enemyName = animal->getName();
	char enemyToken = animal->getToken();
	int enemySize = animal->getSize();
	int enemySpeed = animal->getSpeed();
	int enemyDefence = ((Carnivore*)animal)->getDefence();
	int ownSize = getSize();
	int ownSpeed = getSpeed();
	int ownAttack = getAttack();

	if (enemyToken == 'H')  // if is herbivor
	{
		if ((ownSize >= enemySize) && (ownSpeed > enemySpeed))
		{
			setHungerCount(0);
			animal->Die();
		}
	}
	else
	{
		if (ownSize == 10) // if bear adult
		{
			setHungerCount(0);
			animal->Die();
		}
		else if (ownSize > enemySize)
		{
			setHungerCount(0);
			animal->Die();
		}
		else if (ownSize == enemySize)
		{
			if (ownAttack > enemyDefence)
			{
				setHungerCount(0);
				animal->Die();
			}
		}
	}
}