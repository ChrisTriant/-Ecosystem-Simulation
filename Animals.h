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
	bool inHibernation;
public:
	Animal(int s,int eC,int sp,std::string name,int x,int y,bool hib, char tok);
	void Move();
	virtual void Eat();
	virtual void Raise(int, int, int, int, int, int);
	int getSize();
	int getSpeed();
	int getEatenFood();
	void incEatenFood(int);
	void setEatenFood(int);
	void incEatCount();
	int getEatCount();
	std::string getName();
	void setHungerCount(int);
	void Die();
	bool isalive();
	char getToken();
	bool CanHibernate();
	bool isAdult();
	void Hibernate();
	void Wake();
};

class Herbivor: public Animal{
private:
	bool canClimb;
	int neededFood;
public:
	Herbivor(int s, int sp, int nf, bool cc, int eC,std::string name,int x,int y,bool hib);
	virtual void Eat(Plant* plant);
	void Eat(Animal* animal);
	void Raise(int s, int smax, int sp, int spmax, int ec, int ecmax, int nf, int nfmax);
	bool getClimb();
	int getNeededFood();
};

class Deer:public Herbivor {
public:
	Deer(int x,int y);
	void Eat(Plant* plant);
};

class Rabbit:public Herbivor {
public:
	Rabbit(int x, int y);
	void Eat(Plant* plant);
};

class GroundHog:public Herbivor{
public:
	GroundHog(int x, int y);
	void Eat(Plant* plant);
};

class Salmon :public Herbivor {
public:
	Salmon(int x, int y);
	void Eat(Plant* plant);
};

class Carnivore :public Animal {
private:
	int attack;
	int defence;
protected:

public:
	Carnivore(int s, int eC, int sp, int a, int d, std::string n, int x, int y,bool hib);
	int getDefence();
	virtual void Eat(Animal*);
	int getAttack();
};

class Fox :public Carnivore {
	/*
	** can walk anywhere
	*/
private:

protected:

public:
	Fox(int x, int y);
	void Eat(Animal*);
};

class Wolf :public Carnivore {
	/*
	** can walk anywhere
	*/
private:

protected:

public:
	Wolf(int x, int y);
	void Eat(Animal*);
};

class Bear :public Carnivore {
	/*
	** can walk anywhere
	** falls in xeimeria narki
	*/
private:

protected:

public:
	Bear(int x, int y);
	void Eat(Animal*);
};



