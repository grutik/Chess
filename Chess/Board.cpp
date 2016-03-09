#include "Board.h"



Board::Board()
{
	bool draw_white = true;

	for (int i = 0; i < Board::numberOfFields; i++)
	{
		for (int j = 0; j < Board::numberOfFields; j++)
		{
			int color = draw_white ? 1 : 0;
			fields[i][j] = Field(i, j, color);

			draw_white = !draw_white;
		}
		draw_white = !draw_white;
	}
}


Board::~Board()
{
}
