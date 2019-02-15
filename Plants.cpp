#include"Plants.h"
using namespace std;

Plant::Plant(int t, int s, int l, int lf) :token(t), sickProb(s), life(l), lifeFactor(lf) {
	if (token == 'G') {
		name = "Grass";
	}
	else if (token == 'A') {
		name = "Algae";
	}
	else if (token == 'O') {
		name = "Oak";
	}
	else if (token == 'P') {
		name = "Pine";
	}
	else if (token == 'M') {
		name = "Maple";
	}
}
bool Plant::isSick() {
	return sick;
}

void Plant::operate() {}
void Plant::breed() {

}

void Plant::IncLife() {
	life += lifeFactor;
}
void Plant::LoseLife(int ehp) {
	life -= ehp;
}