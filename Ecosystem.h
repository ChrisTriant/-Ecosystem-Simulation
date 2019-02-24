#include<iostream>
#include"Tile.h"


class Ecosystem {
private:
	Tile* **terrain ;
	int terrain_size;
	const int hill_number = 2;
	int waterT;
	int hillT;
	int valleyT;
	int dayOfYear;
	int season;
	int simDuration;
	int	plants_growthPeriod;
	int	animal_growthPeriod;
	int	plants_breedingRepPeriod;
	int	herbivors_breedingRepPeriod;
	int	carnivore_breedingRepPeriod;
	int timesSeasonChanged;
	int hourOfDay;
public:
	Ecosystem(int, int, int);
	void print_Eco();
	void GenerateRiver();
	void GenerateLake();
	void GenerateHills();
	void GenerateMeadow();
	void CountElements();
	void PlacePlants();
	void PlaceAnimals();
	void RunEcosystem();
	void DailyReset();
	void ApplySeason();
	void ResetHunger();
	void AnimalBreeding(int, int);
	void GiveBirth(Animal *,int, int);
	void PlantBreading(int, int);
	Tile* FindFreeTile(int&, int&);
	void AnimalSleep();
	void AnimalWake();
	void EndDay();
};
