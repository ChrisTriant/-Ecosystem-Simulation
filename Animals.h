#include<iostream>
#include<cstring>

class Animal {
private:
	std::string name;
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
	Animal();
	void Move();
	void Eat();
	void Raise();
};