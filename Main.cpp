#include<iostream>
#include"Ecosystem.h"
using namespace std;
int main(void) {
	int terrain_size;
	cout << "Give terrain_size (At least 10)" << endl;
	cin >> terrain_size;
	if (terrain_size < 10) {
		cout << "ERROR! Invalid number";
		return -1;
	}
	Ecosystem eco(terrain_size);
	eco.print_Eco();
	cout << endl;
	system("pause");
	return 0;
}