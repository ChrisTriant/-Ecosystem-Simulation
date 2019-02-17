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
	Animal(int s,int eC,int sp,std::string name,int x,int y,bool hib);
	void Move();
	virtual void Eat();
	virtual void Raise();
};

class Herbivor: public Animal{
private:
	char token='H';
	bool canClimb;
	int neededFood;
public:
	Herbivor(int s, int sp, int nf, bool cc, int eC,std::string name,int x,int y,bool hib);
	void Eat();
};

class Deer:public Herbivor {
public:
	Deer(int x,int y);

};

class Rabbit:public Herbivor {
public:
	Rabbit(int x, int y);
};

class GroundHog:public Herbivor{
public:
	GroundHog(int x, int y);
};

class Salmon :public Herbivor {
public:
	Salmon(int x, int y);
};

class Carnivore :public Animal {
private:
	int attack;
	int defence;
protected:

public:
	Carnivore(int s, int eC, int sp, int a, int d, std::string n, int x, int y,bool hib);
	// otan faei kano to hungerCount = 0
};

class Fox :public Carnivore {
	/* alepu katiki mono se pediada
	** can walk anywhere
	** can eat any smaller(<=) and slower(<) herbivore
	** can't eat solomo
	** if fight with carnivore -> biggest size win
	** if same size -> biggest attack wins
	** alepu growth -> all stats +1
	** megisto growth -> 4,5,5,6,6 */
private:

protected:

public:
	Fox(int x, int y);
};

class Wolf :public Carnivore {
	/* likos katiki opudipote den iparxi nero
	** can walk anywhere
	** can eat any smaller(<=) and slower(<) herbivore
	** can't eat solomo
	** if fight with carnivore -> biggest size win
	** if same size -> biggest attack wins
	** alepu growth -> all stats +2 | (size +1)
	** megisto growth -> 7,8,6,8,8 */
private:

protected:

public:
	Wolf(int x, int y);
};

class Bear :public Carnivore {
	/* bear katiki mono vuno
	** can walk anywhere
	** can eat any anything except bears
	** adult bear can fuck anyone
	** falls in xeimeria narki
	** alepu growth -> all stats +2 | (speed + 0)
	** megisto growth -> 10,10,10,4,10 */
private:

protected:

public:
	Bear(int x, int y);
};



