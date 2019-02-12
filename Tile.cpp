#include"Tile.h"

Tile::Tile(char c)
{
	landscape = c;
}

char Tile::get_land()
{
	return landscape;
}
