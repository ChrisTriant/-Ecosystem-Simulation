#include<iostream>
#include<string>
#include"Plants.h"

class Animal {
private:
	std::string name;
	char token;
	int size;
	int hungerCount;
	int eatenFood;
	int eatCount;
	int x, y;
	bool isAlive;
	bool isHungry;
	bool inHeat;
	int speed;
	bool Hibernates;
	bool Adult;
	bool moved;
	bool inHibernation;
public:
	Animal(int s, int eC, int sp, std::string name, int x, int y, bool hib, char tok);
	virtual bool Move(int, int, char);
	void setXY(int, int);
	virtual bool Eat(Plant*);
	virtual bool Eat(Animal*);
	virtual void Raise();
	int getSize();
	int getSpeed();
	int getEatenFood();
	void incEatenFood(int);
	void setEatenFood(int);
	void incEatCount();
	void incHunger();
	int getHunger();
	int getEatCount();
	std::string getName();
	void setHungerCount(int);
	void Die();
	bool isalive();
	char getToken();
	bool CanHibernate();
	bool isHiber();
	bool isAdult();
	void Hibernate();
	void Wake();
	void incSize();
	void incSpeed();
	void becameAdult();
	int getX();
	int getY();
	bool hasMoved();

	void setMoved(bool);
};

class Herbivor : public Animal {
private:
	bool canClimb;
	int neededFood;
public:
	Herbivor(int s, int sp, int nf, bool cc, int eC, std::string name, int x, int y, bool hib);
	virtual bool Eat(Plant* plant);
	virtual bool Move(int, int, char);
	bool Eat(Animal* animal);
	virtual void Raise();
	bool getClimb();
	int getNeededFood();
	void incNeededFood();
};

class Deer :public Herbivor {
public:
	Deer(int x, int y);
	bool Move(int, int, char);
	bool Eat(Plant* plant);
	void Raise();
};

class Rabbit :public Herbivor {
public:
	Rabbit(int x, int y);
	bool Eat(Plant* plant);
	bool Move(int, int, char);
	void Raise();
};

class GroundHog :public Herbivor {
public:
	GroundHog(int x, int y);
	bool Move(int, int, char);
	bool Eat(Plant* plant);
	void Raise();
};

class Salmon :public Herbivor {
private:
	bool newborn;
public:
	Salmon(int x, int y);
	bool Eat(Plant* plant);
	bool Move(int, int, char);
	bool isNewB();
	void setNewB(bool);
	void Raise();
};

class Carnivore :public Animal {
private:
	int attack;
	int defence;
protected:

public:
	Carnivore(int s, int eC, int sp, int a, int d, std::string n, int x, int y, bool hib);
	int getDefence();
	bool Move(int, int, char);
	void incDefence();
	virtual bool Eat(Animal*);
	int getAttack();
	void incAttack();
	virtual void Raise();
};

class Fox :public Carnivore {

public:
	Fox(int x, int y);
	bool Eat(Animal*);
	void Raise();
};

class Wolf :public Carnivore {

public:
	Wolf(int x, int y);
	bool Eat(Animal*);
	void Raise();
};

class Bear :public Carnivore {

public:
	Bear(int x, int y);
	bool Eat(Animal*);
	void Raise();
};

