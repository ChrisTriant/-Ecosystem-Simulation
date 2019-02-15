#include<iostream>
#include<ctime>
#include<cstring>

class Plant {
private:
	bool sick;	/* den exo brei pote prepei na ipologizo an to fito einai arrwsto.
				 * Oute 3eroume gia poso tha einai arrwsto */
	std::string name;
	int x, y;
	char token;
	int *breedingProb;
	int sickProb;
	int life;
	int lifeFactor;
protected:
	virtual void IncLife();
	virtual void LoseLife(int elf);
public:
	Plant(int t, int s, int l, int lf);
	bool isSick();
	virtual void operate() {}
	void breed(); // den 3ero ti prepei na kanei afto
};



class Seedless : public Plant {
private:
	
public:
	void operate()
	{
		if (isSick())
		{
			life -= lifeFactor;
		}
		else
		{
			life += lifeFactor;
		}
		srand(time(NULL));
		int prob = rand() % 100 + 1;
		if (prob <= breedingProb[season] && (!isSick()))
		{
			breed();
		}
	}
};

class Grass : public Seedless {
public:
	Grass():Plant('G',15,5,2)
	{ //prepei na fitrwnei opou yparxei pediada
		breedingProb[season] = 15;
	}
};

class Algae : public Seedless {
	Algae()
	{ // anaptyssetai mono ekei pou yparxei nero
		token = 'A';
		life = 5;
		breedingProb[season] = 25;
		lifeFactor = 2;
		sickProb = 25;
	}
};

class Seeded :public Plant {
private:
	int foliage;
	int seeds;
	int size;
public:
	void GotEaten(int poso)
	{
		if (seeds > 0)
		{
			seeds -= poso; // ti tha geinei an to poso einai emgalitero apo seeds?
		}
		else
		{
			foliage -= poso;
			life -= poso;
		}
	}
	void operate()
	{
		if (isSick())
		{
			life -= lifeFactor;
			seeds -= (2 * lifeFactor);
			// na doume afto me to foliage kai to lifeFactor
		}
		else
		{
			life += lifeFactor;
			seeds += (2 * lifeFactor);
		}
		srand(time(NULL));
		int prob = rand() % 100 + 1;
		if (prob <= breedingProb[season] && (!isSick()))
		{
			breed();
		}
	}
};

class Oak :public Seeded {

public:
	Oak()
	{ // mono pediada
		token = 'O';
		size = 5;
		seeds = 15;
		foliage = 30;
		//life = 5; // nomizw ta seeded den leitourgoun me life.
		breedingProb[season] = 20;
		lifeFactor = 15;
		sickProb = 20;
	}
};
class Pine :public Seeded {
	Pine()
	{ // mono pediada
		token = 'P';
		size = 5;
		seeds = 20;
		foliage = 40;
		//life = 5; // nomizw ta seeded den leitourgoun me life.
		breedingProb[season] = 15;
		lifeFactor = 20;
		sickProb = 15;
	}
};
class Maple :public Seeded {
	Maple()
	{ // anaptyssetai se stereo perivallon
		token = 'M';
		size = 2;
		seeds = 10;
		foliage = 20;
		//life = 5; // nomizw ta seeded den leitourgoun me life.
		breedingProb[season] = 5;
		lifeFactor = 10;
		sickProb = 5;
	}
};
