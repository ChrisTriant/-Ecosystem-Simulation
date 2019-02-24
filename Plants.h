#include<iostream>
#include<ctime>
#include<cstring>

class Plant {
private:
	bool sick;	/* den exo brei pote prepei na ipologizo an to fito einai arrwsto.
				 * Oute 3eroume gia poso tha einai arrwsto 
				 * Mallon den xreiazetai to sick (den uparxei sthn ekfwnhsh
				 * apla leei oti mporei na mhn anaparax8ei logo pithanotiton illnessprob
				 * opote mallon sto grow() xreiazetai apla na baloume ena if pou koita tis pithanothtes na einai arrwsto
				 */
	std::string name;
	int x, y;
	char token;
	int breedingProb;
	int illnessProb;
	int life;
	int lifeFactor;

public:
	Plant(char, int, int, int, int, int, int);
	void IncLife();
	virtual void LoseLife(int elf);
	void LoseLife();
	int getLife();
	bool isSick();
	bool isAlive();
	virtual int getSize();
	int getLifeFac();
	int getToken();
	std::string getName();
	virtual void operate();
	virtual void grow(int);
	int getIllnessProb(int);
	int getBreedingProb(int);
};



class Seedless : public Plant {
private:
	
public:
	Seedless(char, int, int, int, int, int, int);
	void operate();
};

class Grass : public Seedless {
public:
	Grass(int x,int y);
};

class Algae : public Seedless {
public:
	Algae(int x, int y);
};

class Seeded :public Plant {
private:
	int foliage;
	int seeds;
	int size;
public:
	Seeded(char, int, int, int, int, int, int, int, int, int);
	void LoseLife(int ehp);
	void operate();
	int getSize();
	void LoseSeed();
	void LoseFoliage();

};

class Oak :public Seeded {

public:
	Oak(int x,int y);
};

class Pine :public Seeded {
public:
	Pine(int x,int y);
};

class Maple :public Seeded {
public:
	Maple(int x, int y);
};
