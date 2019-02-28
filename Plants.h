#include<iostream>
#include<ctime>
#include<cstring>

class Plant {
private:
	bool sick;	
	std::string name;
	int x, y;
	char token;
	int breedingProb[4];
	int illnessProb[4];
	int life;
	int lifeFactor;
	bool newborn;
public:
	Plant(char, int, int, int, int);
	void IncLife();
	virtual void LoseLife(int elf);
	void LoseLife();
	int getLife();
	bool isSick();
	bool isAlive();
	virtual int getSize();
	int getLifeFac();
	char getToken();
	std::string getName();
	virtual void operate();
	virtual void grow(int);
	int getIllnessProb(int);
	int getBreedingProb(int);
	bool isNewB();
	void setNewB(bool);
};



class Seedless : public Plant {
private:

public:
	Seedless(char, int, int, int, int, int, int);
	void operate();
};

class Grass : public Seedless {
public:
	Grass(int x, int y);
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
	int getFoliage();
	int getSeeds();
};

class Oak :public Seeded {

public:
	Oak(int x, int y);
};

class Pine :public Seeded {
public:
	Pine(int x, int y);
};

class Maple :public Seeded {
public:
	Maple(int x, int y);
};
