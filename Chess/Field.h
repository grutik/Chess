#pragma once
class Field
{
public:

	int x;
	int y;
	int color;
	bool selected;

	Field();
	Field(int x, int y, int color);
	void Select();
	void Unselect();
	~Field();
};

