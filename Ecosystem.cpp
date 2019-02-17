#include"Ecosystem.h"
#include<ctime>
#include<Windows.h>
using namespace std;


Ecosystem::Ecosystem(int t) :terrain_size(t) {
	terrain = new Tile**[terrain_size];
	waterT = 0;
	hillT = 0;
	valleyT = 0;
	for (int i = 0; i < terrain_size; i++) {
			terrain[i] = new Tile*[terrain_size-1];
	}
	for (int i = 0; i < terrain_size; i++) {
		for (int j=0; j < terrain_size; j++) {
			terrain[i][j] = NULL;
		}
	}
	GenerateRiver();
	GenerateLake();
	GenerateHills();
	GenerateMeadow();
	CountElements();
	PlacePlants();
	PlaceAnimals();
}

void Ecosystem::print_Eco() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < terrain_size; i++) {
		for (int s=0; s < terrain_size; s++) {
			cout << "-----";
		}
		cout << endl;
		for (int j = 0; j < terrain_size; j++) {
			if (terrain[i][j] != NULL) {
				cout << "| " ;
				if (terrain[i][j]->get_land() == '#') {
					SetConsoleTextAttribute(hConsole, 1);
					cout << terrain[i][j]->get_land();
					SetConsoleTextAttribute(hConsole, 7);
					cout << " |";
				}
				else if(terrain[i][j]->get_land() == '\"'){
					SetConsoleTextAttribute(hConsole, 2);
					cout << terrain[i][j]->get_land();
					SetConsoleTextAttribute(hConsole, 7);
					cout<< " |";
				}
				else if (terrain[i][j]->get_land() == '^') {
					SetConsoleTextAttribute(hConsole, 6);
					cout << terrain[i][j]->get_land();
					SetConsoleTextAttribute(hConsole, 7);
					cout << " |";
				}
			}
			
			
		}
		cout << endl;
	}
	for (int s = 0; s < terrain_size; s++) {
		cout << "-----";
	}
}

void Ecosystem::GenerateRiver() {
	srand(time(NULL));
	int r = rand() % (terrain_size - 9) + 5;
	for (int i = 0; i < terrain_size; i++) {
		terrain[i][r] = new Tile('#');
		int t = rand() % (10) + 1;
		if (t < 4) {				//30% chance to move
			t = rand() % 4 + 1;
			switch (t){
			case 1:										//move once to the right
				if (r + 1 < terrain_size) {
					terrain[i][r + 1] = new Tile('#');
					r++;
				}
				break;
			case 2:										//move twice to the right
				if (r + 1 < terrain_size) {					
					terrain[i][r + 1] = new Tile('#');
					r++;
				}
				if (r + 1 < terrain_size) {					
					terrain[i][r + 1] = new Tile('#');
					r++;
				}
				break;
			case 3:											//move once to the left
				if (r -1 >= 0) {
					terrain[i][r - 1] = new Tile('#');
					r--;
				}
				break;
			case 4:											//move twice to the left
				if (r - 1 >= 0) {
					terrain[i][r - 1] = new Tile('#');
					r--;
				}
				if (r - 1 >= 0) {
					terrain[i][r - 1] = new Tile('#');
					r--;
				}
				break;
			}

		}
	}
	

}
void Ecosystem::GenerateLake()
{
	srand(time(NULL));
	int lakesize = rand() % (terrain_size / 3)+2 ;
	int x = rand() % (terrain_size - lakesize);
	int y = rand() % (terrain_size - lakesize);
	for (int i=x; i < x+lakesize; i++) {
		for (int j=y; j < y+lakesize; j++) {
			terrain[i][j] = new Tile('#');
		}
	}
}

void Ecosystem::GenerateHills()
{
	srand(time(NULL));
	for (int i = 0; i < hill_number; i++)
	{
		int hillsize = rand() % 3 + 2;
		int x = rand() % (terrain_size - hillsize);
		int y = rand() % (terrain_size - hillsize);
		for (int i = x; i < x + hillsize; i++) {
			for (int j = y; j < y + hillsize; j++) {
				if (terrain[i][j] == NULL) terrain[i][j] = new Tile('^');
			}
		}
	}
}

void Ecosystem::GenerateMeadow()
{
	for (int i = 0; i < terrain_size; i++) {
		for (int j = 0; j < terrain_size; j++) {
			if (terrain[i][j] == NULL) {
				terrain[i][j] = new Tile('\"');
			}
		}
	}
}

void Ecosystem::CountElements() {
	for (int i = 0; i < terrain_size; i++) {
		for (int j = 0; j < terrain_size; j++) {
			if (terrain[i][j]->get_land() == '#') {
				waterT++;
			}
			else if (terrain[i][j]->get_land() == '^') {
				hillT++;
			}
			else {
				valleyT++;
			}
		}
	}
}

void Ecosystem::PlacePlants()
{
	srand(time(NULL));
	for (int i = 0; i < terrain_size; i++)
	{
		for (int j = 0; j < terrain_size; j++)
		{
			int prob = rand() % 100 + 1;
			if (prob < 50)
			{
				if (terrain[i][j]->get_land() == '#')
				{    //algae
					terrain[i][j]->addPlant(new Algae(i,j));
					cout << "Algae generated in tile " << i << "-" << j << endl;
				}
				else if (terrain[i][j]->get_land() == '^')
				{ // maple, pine
					int morp = rand() % 1;
					if (morp)
					{
						terrain[i][j]->addPlant(new Maple(i,j));
						cout << "Maple generated in tile " << i << "-" << j << endl;
					}
					else
					{
						terrain[i][j]->addPlant(new Pine(i,j));
						cout << "Pine generated in tile " << i << "-" << j << endl;
					}
				}
				else
				{ //grass, oak, maple
					int grom = rand() % 3 + 1;
					switch (grom) {
					case 1:
						terrain[i][j]->addPlant(new Grass(i,j));
						cout << "Grass generated in tile " << i << "-" << j << endl;
						break;
					case 2:
						terrain[i][j]->addPlant(new Oak(i,j));
						cout << "Oak generated in tile " << i << "-" << j << endl;
						break;
					case 3:
						terrain[i][j]->addPlant(new Maple(i,j));
						cout << "Maple generated in tile " << i << "-" << j << endl;
						break;
					default:
						break;
					}
				}
			}
		}
	}
}


void Ecosystem::PlaceAnimals()
{
	srand(time(NULL));
	for (int i = 0; i < terrain_size; i++)
	{
		for (int j = 0; j < terrain_size; j++)
		{
			int prob = rand() % 100 + 1;
			if (prob < 50)
			{
				int amount = rand() % 5 + 1;
				if (terrain[i][j]->get_land() == '#')
				{	
					for (int a = 0; a < amount; a++) {
						terrain[i][j]->addAnimal(new Salmon(i, j));
						cout << "Salmon generated in tile " << i << "-" << j << endl;
					}
				}
				else if (terrain[i][j]->get_land() == '^')
				{    // wolf, Bear
					for (int a = 0; a < amount; a++) {
						int anim = rand() % 2 ;
						if (anim==1)
						{
							terrain[i][j]->addAnimal(new Wolf(i, j));
							cout << "Wolf generated in tile " << i << "-" << j << endl;
						}
						else
						{
							terrain[i][j]->addAnimal(new Bear(i, j));
							cout << "Bear generated in tile " << i << "-" << j << endl;
						}
					}
				}
				else
				{    //Wolf, Fox
					for (int a = 0; a < amount; a++) {
						int anim = rand() % 4 + 1;
						switch (anim) {
						case 1:
							terrain[i][j]->addAnimal(new Wolf(i, j));
							cout << "Wolf generated in tile " << i << "-" << j << endl;
							break;
						case 2:
							terrain[i][j]->addAnimal(new Fox(i, j));
							cout << "Fox generated in tile " << i << "-" << j << endl;
							break;
						case 3:
							terrain[i][j]->addAnimal(new Rabbit(i, j));
							cout << "Rabbit generated in tile " << i << "-" << j << endl;
							break;
						case 4:
							terrain[i][j]->addAnimal(new Deer(i, j));
							cout << "Deer generated in tile " << i << "-" << j << endl;
							break;
						case 5:
							terrain[i][j]->addAnimal(new GroundHog(i, j));
							cout << "Groundhog generated in tile " << i << "-" << j << endl;
							break;
						default:
							break;
						}
					}
				}
			}
		}
	}
}