#include "Field.h"



Field::Field(int xx, int yy, int newColor)
{
	_x = xx;
	_y = yy;
	_color = newColor;
	_selected = false;
	_fig = nullptr;
}

Field::~Field()
{
}

int Field::GetX()
{
	return _x;
}

int Field::GetY()
{
	return _y;
}

int Field::GetColor()
{
	return _color;
}


bool Field::HasFigure()
{
	return _fig != nullptr;
}

Figure * Field::GetFigure()
{
	return _fig;
}

void Field::SetFigure(Figure * figure)
{
	_fig = figure;
}

void Field::RemoveFigure()
{
	_fig = nullptr;
}


int Field::IsSelected()
{
	return _selected;
}

void Field::Select()
{
	_selected = true;
}

void Field::Unselect()
{
	_selected = false;
}





