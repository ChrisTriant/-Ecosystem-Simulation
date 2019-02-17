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
	int illnessProb;
	int life;
	int lifeFactor;

public:
	Plant(char t, int s, int l, int lf,int x,int y);
	void IncLife();
	void LoseLife(int elf);
	bool isSick();
	bool isAlive();
	int getLifeFac();
	virtual void operate();
	void breed(); // den 3ero ti prepei na kanei afto
};



class Seedless : public Plant {
private:
	
public:
	Seedless(char t, int s, int l, int lf,int x,int y);
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
	Seeded(char t, int s, int l, int lf, int f, int sd, int sz,int x,int y);
	void GotEaten(int ehp);
	void operate();
protected:
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
