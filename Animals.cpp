#include"Animals.h"

using namespace std;

Animal::Animal(int s, int eC, int sp, string name, int x, int y, bool hib, char tok) :size(s), eatCount(eC), speed(sp), name(name), x(x), y(y), Hibernates(hib), isAlive(true), token(tok), Adult(false) {
	eatenFood = 0;
	hungerCount = 0;
	Wake();
}

bool Animal::Move(int, int, char)
{
	return false;
}

void Animal::setXY(int posox, int posoy)
{
	x = posox;
	y = posoy;
}


bool Animal::Eat(Plant*)
{
	return true;
}
bool Animal::Eat(Animal*)
{
	return true;
}

void Animal::Raise()
{

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

void Animal::incHunger()
{
	hungerCount++;
}

int Animal::getHunger()
{
	return hungerCount;
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

bool Animal::isHiber()
{
	return inHibernation;
}

bool Animal::isAdult()
{
	return Adult;
}

void Animal::Hibernate()
{
	inHibernation = true;
}

void Animal::Wake()
{
	inHibernation = false;
}

void Animal::incSize()
{
	size++;
}

void Animal::incSpeed()
{
	speed++;
}

void Animal::becameAdult()
{
	Adult = true;
	//cout << "Adult" << endl;
}

int Animal::getX()
{
	return x;
}

int Animal::getY()
{
	return y;
}

bool Animal::hasMoved()
{
	return moved;
}

void Animal::setMoved(bool value)
{
	moved = value;
}

/*########################################*/

/*#############HERBIVORS##################*/
Herbivor::Herbivor(int s, int sp, int nf, bool cc, int eC, string name, int x, int y, bool hib) :Animal(s, eC, sp, name, x, y, hib, 'H'), canClimb(cc), neededFood(nf)
{
}

bool Herbivor::Eat(Plant * plant)
{
	return true;
}

bool Herbivor::Move(int, int, char)
{
	return false;
}

bool Herbivor::Eat(Animal * animal)
{
	cout << "im tired of being a vegan\n";
	return true;
	// lol
}

void Herbivor::Raise()
{
	/*	Animal::Raise(s, smax, sp, spmax, ec, ecmax);
		while (nf > 0 && neededFood < nfmax)
		{
			neededFood++;
			nf--;
		}*/
}

bool Herbivor::getClimb()
{
	return canClimb;
}

int Herbivor::getNeededFood()
{
	return neededFood;
}

void Herbivor::incNeededFood()
{
	neededFood++;
}

/*#############DEER##################*/
Deer::Deer(int x, int y) :Herbivor(2, 4, 4, false, 2, "Deer", x, y, false)
{

}

bool Deer::Move(int x, int y, char type)
{
	setXY(x, y);
	return true;

}

bool Deer::Eat(Plant * plant)
{
	if (plant == NULL || !(plant->isAlive())) {
	//	cout << "There is no plant in this tile\n";
		return false;
	}
	if (getEatenFood() == getNeededFood()) {
	//	cout << "Deer is no longer hungry\n";
		return false;
	}
	if (getSize() + 4 > plant->getSize()) {

		if (getEatCount() < plant->getLife()) {
			incEatenFood(getEatCount());
			//cout << "Deer ate " << plant->getName() << endl;
			plant->LoseLife(getEatCount());
		}
		else {
			incEatenFood(plant->getLife());
	//		cout << "Deer ate " << plant->getName() << endl;
			plant->LoseLife(plant->getLife());
		}
		if (getEatenFood() == getNeededFood()) {
	//		cout << "Deer is no longer hungry\n";
			setHungerCount(0);
			return true;
		}
	}
	return false;
}

void Deer::Raise()
{
	int s = 1;
	while (s > 0 && getSize() < 5)
	{
		incSize();
		s--;
	}
	if (getSize() == 5)
	{
		becameAdult();
	}

	int sp = 2;
	while (sp > 0 && getSpeed() < 8)
	{
		incSpeed();
		sp--;
	}

	int nf = 2;
	while (nf > 0 && getNeededFood() < 8)
	{
		incNeededFood();
		nf--;
	}
	//Herbivor::Raise(1, 5, 2, 8, 0, 0, 2, 8);
}

/*#############RABBIT##################*/


Rabbit::Rabbit(int x, int y) : Herbivor(1, 2, 2, false, 1, "Rabbit", x, y, false) {

}

bool Rabbit::Eat(Plant * plant)
{
	if (plant == NULL || !(plant->isAlive())) {
	//	cout << "There is no plant in this tile\n";
		return false;
	}

	if (getEatenFood() == getNeededFood()) {
//		cout << "Rabbit is no longer hungry\n";
		return true;
	}

	if (plant->getToken() == 'A') {
	//	cout << "Rabbit can't eat algae\n";
		return false;
	}
	if (getSize() >= plant->getSize()) {
		if (getEatCount() < plant->getLife()) {
			incEatenFood(getEatCount());
			plant->LoseLife(getEatCount());
			//cout << "Rabbit ate " << plant->getName() << endl;
		}
		else {
			incEatenFood(plant->getLife());
			plant->LoseLife(plant->getLife());
			//cout << "Groundhog ate " << plant->getName() << endl;
		}
		if (getEatenFood() == getNeededFood()) {
	//	cout << "Rabbit is no longer hungry\n";
			setHungerCount(0);
		}
	}
	return false;
}

bool Rabbit::Move(int x, int y, char type)
{
	//cout << "Rabbit moved from " << getX() << "-" << getY() << " to " << x << " - " << y << endl;
	if (type != '^')
	{
		setXY(x, y);
		return true;
	}
	return false;
}

void Rabbit::Raise()
{
	int s = 1;
	while (s > 0 && getSize() < 2)
	{
		incSize();
		s--;
	}
	if (getSize() == 2)
	{
		becameAdult();
	}

	int sp = 2;
	while (sp > 0 && getSpeed() < 6)
	{
		incSpeed();
		sp--;
	}

	int nf = 1;
	while (nf > 0 && getNeededFood() < 4)
	{
		incNeededFood();
		nf--;
	}
	//Herbivor::Raise(1, 2, 2, 6, 0, 0, 1, 4);
}

/*#############GROUNDHOG##################*/

GroundHog::GroundHog(int x, int y) :Herbivor(2, 3, 3, false, 1, "Groundhog", x, y, true)
{
}

bool GroundHog::Move(int x, int y, char type)
{
	if (isHiber()) {
	//	cout << "Groundhog is in hibernation\n";
		return false;
	}
	if (type != '#')
	{
		setXY(x, y);
		return true;
	}
	return false;
}

bool GroundHog::Eat(Plant * plant)
{
	if (isHiber()) {
		//cout << "Groundhog is in hibernation\n";
		return false;
	}
	if (plant == NULL || !(plant->isAlive())) {
	//	cout << "There is no plant in this tile\n";
		return false;
	}
	if (getEatenFood() == getNeededFood()) {
	//	cout << "Groundhog is no longer hungry\n";
		return true;
	}
	if (plant->getToken() == 'A') {
	//	cout << "Groundhog can't eat algae\n";
		return false;
	}
	if (!getClimb()) {
		if (getSize() >= plant->getSize()) {
			if (getEatCount() < plant->getLife()) {
				incEatenFood(getEatCount());
				plant->LoseLife(getEatCount());
			//	cout << "Groundhog ate " << plant->getName() << endl;
			}
			else {
				incEatenFood(plant->getLife());
				plant->LoseLife(plant->getLife());
			//	cout << "Groundhog ate " << plant->getName() << endl;
			}
			if (getEatenFood() == getNeededFood()) {
		//		cout << "Groundhog is no longer hungry\n";
				setHungerCount(0);
			}
		}
	}
	else {
		if (getSize() * 3 >= plant->getSize()) {
			if (getEatCount() < plant->getLife()) {
				incEatenFood(getEatCount());
				plant->LoseLife(getEatCount());
		//		cout << "Groundhog ate " << plant->getName() << endl;
			}
			else {
				incEatenFood(plant->getLife());
				plant->LoseLife(plant->getLife());
		//		cout << "Groundhog ate " << plant->getName() << endl;
			}
			if (getEatenFood() == getNeededFood()) {
		//		cout << "Groundhog is no longer hungry\n";
				setHungerCount(0);
			}
		}
	}
	return false;
}

void GroundHog::Raise()
{
	int s = 1;
	while (s > 0 && getSize() < 3)
	{
		incSize();
		s--;
	}
	if (getSize() == 3)
	{
		becameAdult();
	}

	int sp = 1;
	while (sp > 0 && getSpeed() < 5)
	{
		incSpeed();
		sp--;
	}

	int nf = 1;
	while (nf > 0 && getNeededFood() < 5)
	{
		incNeededFood();
		nf--;
	}
	//Herbivor::Raise(1, 3, 1, 5, 0, 0, 1, 5);
}

/*#############SALMON##################*/

Salmon::Salmon(int x, int y) :Herbivor(1, 5, 1, false, 1, "Salmon", x, y, false)
{
	becameAdult();
}

bool Salmon::Eat(Plant * plant)
{
	if (plant == NULL || !(plant->isAlive())) {
	//	cout << "There is no plant in this tile\n";
		return false;
	}
	if (getEatenFood() == getNeededFood()) {
	//	cout << "Salmon is no longer hungry\n";
		return true;
	}
	if (getEatCount() < plant->getLife()) {
		incEatenFood(getEatCount());
		plant->LoseLife(getEatCount());
	//	cout << "Salmon ate algae\n";
		if (getEatenFood() == getNeededFood()) {
		//	cout << "Salmon is no longer hungry\n";
			setHungerCount(0);
		}
	}
	else {
		incEatenFood(plant->getLife());
		plant->LoseLife(plant->getLife());
	//	cout << "Salmon ate algae\n";
		if (getEatenFood() == getNeededFood()) {
		//	cout << "Salmon is no longer hungry\n";
			setHungerCount(0);
		}
	}
	return false;
}

bool Salmon::Move(int x, int y, char type)
{
	if (type == '#')
	{
		setXY(x, y);
		return true;
	}
	return false;
}


void Salmon::setNewB(bool nb)
{
	newborn = nb;
}

bool Salmon::isNewB()
{
	return newborn;
}

void Salmon::Raise()
{

}


/* ######## Carnivore ######### */
Carnivore::Carnivore(int s, int eC, int sp, int a, int d, std::string n, int x, int y, bool hib) : Animal(s, eC, sp, n, x, y, hib, 'C'), attack(a), defence(d) {

}

bool Carnivore::Eat(Animal* animal)
{
	return false;
}

int Carnivore::getDefence()
{
	return defence;
}

bool Carnivore::Move(int x, int y, char type)
{
	if (isHiber()) {
		return false;
	}
	//cout << "I fucking moved" << endl;
	setXY(x, y);
	return true;
}

void Carnivore::incDefence()
{
	defence++;
}

int Carnivore::getAttack()
{
	return attack;
}

void Carnivore::incAttack()
{
	attack++;
}

void Carnivore::Raise()
{
}



/* ####### FOX ####### */

Fox::Fox(int x, int y) : Carnivore(1, 2, 1, 1, 1, "Fox", x, y, false) {

}

bool Fox::Eat(Animal* animal) {
	if (getHunger() != 0) 
	{
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
					incEatenFood(1);
					animal->Die();
				//	cout << "Fox is no longer hungry\n";
					return true;
				}
			}
		}
		else
		{
			if (ownSize > enemySize)
			{
				setHungerCount(0);
				incEatenFood(1);
				animal->Die();
			//	cout << "Fox is no longer hungry\n";
				return true;
			}
			else if (ownSize == enemySize)
			{
				if (ownAttack > enemyDefence)
				{
					setHungerCount(0);
					incEatenFood(1);
					animal->Die();
				//	cout << "Fox is no longer hungry\n";
					return true;
				}
			}
		}
	}
	return false;
}


void Fox::Raise()
{
	int s = 1;
	while (s > 0 && getSize() < 4)
	{
		incSize();
		s--;
	}
	if (getSize() == 4)
	{
		becameAdult();
	}

	int sp = 1;
	while (sp > 0 && getSpeed() < 6)
	{
		incSpeed();
		sp--;
	}

	int a = 1;
	while (a > 0 && getAttack() < 5)
	{
		incAttack();
		a--;
	}

	int d = 1;
	while (d > 0 && getDefence() < 5)
	{
		incDefence();
		d--;
	}
}

/* ###### WOLF ####### */

Wolf::Wolf(int x, int y) : Carnivore(1, 2, 2, 2, 2, "Wolf", x, y, false) {

}


bool Wolf::Eat(Animal* animal) {
	if (getHunger() != 0)
	{
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
					incEatenFood(1);
					animal->Die();
				//	cout << "Wolf is no longer hungry\n";
					return true;
				}
			}
		}
		else
		{
			if (ownSize > enemySize)
			{
				setHungerCount(0);
				incEatenFood(1);
				animal->Die();
			//	cout << "Wolf is no longer hungry\n";
				return true;
			}
			else if (ownSize == enemySize)
			{
				if (ownAttack > enemyDefence)
				{
					setHungerCount(0);
					incEatenFood(1);
					animal->Die();
				//	cout << "Wolf is no longer hungry\n";
					return true;
				}
			}
		}
	}
	return false;
}

void Wolf::Raise()
{
	int s = 1;
	while (s > 0 && getSize() < 7)
	{
		incSize();
		s--;
	}
	if (getSize() == 7)
	{
		becameAdult();
	}

	int sp = 2;
	while (sp > 0 && getSpeed() < 8)
	{
		incSpeed();
		sp--;
	}

	int a = 2;
	while (a > 0 && getAttack() < 8)
	{
		incAttack();
		a--;
	}

	int d = 2;
	while (d > 0 && getDefence() < 6)
	{
		incDefence();
		d--;
	}
}

/* ###### Bear ####### */

Bear::Bear(int x, int y) : Carnivore(3, 5, 4, 6, 6, "Bear", x, y, true) {

}


bool Bear::Eat(Animal* animal) {
	if (isHiber()) {
		cout << "Bear is in hibernation\n";				
		setHungerCount(0);
		incEatenFood(1);
		return true;
	}
	if (getHunger() != 0)
	{
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
			if (animal->getName()=="Salmon")
			{

				animal->Die();
				//		cout << "Bear is no longer hungry\n";
				return true;
			}
			if ((ownSize >= enemySize) && (ownSpeed > enemySpeed))
			{

				animal->Die();
		//		cout << "Bear is no longer hungry\n";
				return true;
			}
		}
		else
		{
			if (ownSize == 10) // if bear adult
			{
				setHungerCount(0);
				incEatenFood(1);
				animal->Die();
		//		cout << "Bear is no longer hungry\n";
				return true;
			}
			else if (ownSize > enemySize)
			{
				setHungerCount(0);
				animal->Die();
				incEatenFood(1);
	//			cout << "Bear is no longer hungry\n";
				return true;
			}
			else if (ownSize == enemySize)
			{
				if (ownAttack > enemyDefence)
				{
					setHungerCount(0);
					incEatenFood(1);
					animal->Die();
		//			cout << "Bear is no longer hungry\n";
					return true;
				}
			}
		}
	}
	return false;
}

void Bear::Raise()
{
	int s = 2;
	while (s > 0 && getSize() < 10)
	{
		incSize();
		s--;
	}
	if (getSize() == 10)
	{
		becameAdult();
	}

	int a = 2;
	while (a > 0 && getAttack() < 10)
	{
		incAttack();
		a--;
	}

	int d = 2;
	while (d > 0 && getDefence() < 10)
	{
		incDefence();
		d--;
	}
}
