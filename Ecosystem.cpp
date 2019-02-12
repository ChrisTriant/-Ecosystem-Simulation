#include"Ecosystem.h"
#include<ctime>
#include<Windows.h>
using namespace std;


Ecosystem::Ecosystem(int t) :terrain_size(t) {
	terrain = new Tile**[terrain_size];
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
				}else {
					SetConsoleTextAttribute(hConsole, 3);
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
	int lakesize = rand() % (terrain_size / 3)+1 ;
	int x = rand() % (terrain_size - lakesize);
	int y = rand() % (terrain_size - lakesize);
	for (int i=x; i < x+lakesize; i++) {
		for (int j=y; j < y+lakesize; j++) {
			terrain[i][j] = new Tile('@');
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
