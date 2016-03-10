#include "Field.h"



Field::Field()
{
}

Field::Field(int xx, int yy, int newColor)
{
	x = xx;
	y = yy;
	color = newColor;
	selected = false;
	currentFigure = nullptr;
}

void Field::Select()
{
	selected = true;
}

void Field::Unselect()
{
	selected = false;
}


Field::~Field()
{
}
