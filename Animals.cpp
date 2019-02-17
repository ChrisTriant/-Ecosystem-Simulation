#include"Animals.h"

using namespace std;

Animal::Animal(int s, int eC, int sp,string name,int x,int y,bool hib) :size(s), eatCount(eC), speed(sp),name(name),x(x),y(y),Hibernates(hib) {
}

void Animal::Move()
{
}

void Animal::Eat()
{
}

void Animal::Raise()
{
}
/*########################################*/

/*#############HERBIVORS##################*/
Herbivor::Herbivor(int s,int sp,int nf,bool cc,int eC,string name,int x,int y,bool hib):Animal(s,eC,sp,name,x,y,hib),canClimb(cc),neededFood(nf)
{
}

void Herbivor::Eat()
{

}

Deer::Deer(int x,int y):Herbivor(2,4,4,false,2,"Deer",x,y,false)
{

}

Rabbit::Rabbit(int x, int y) : Herbivor(1, 2, 2,false, 1,"Rabbit" ,x, y,false) {

}

GroundHog::GroundHog(int x, int y):Herbivor(2,3,3,true,1,"Groundhog",x,y,true)
{
}

Salmon::Salmon(int x, int y):Herbivor(1,5,1,false,1,"Salmon",x,y,false)
{
}


// constructors

/* ######## Carnivore ######### */
Carnivore::Carnivore(int s, int eC, int sp, int a, int d, std::string n, int x, int y,bool hib) : Animal(s, eC, sp, n, x, y,hib), attack(a), defence(d) {

}

/* ####### FOX ####### */

Fox::Fox(int x, int y) : Carnivore(1, 2, 1, 1, 1, "Fox", x, y,false) {

}

/* ###### WOLF ####### */

Wolf::Wolf(int x, int y) : Carnivore(1, 2, 2, 2, 2, "Wolf", x, y,false) {

}

/* ###### Bear ####### */

Bear::Bear(int x, int y) : Carnivore(3, 5, 4, 6, 6, "Bear", x, y,true) {

}
