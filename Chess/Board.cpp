#include "Board.h"



Board::Board()
{
	CreateFields();
	SetFigures();
}

Board::~Board()
{
}

void Board::CreateFields() {
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

void Board::SetFigures() {

	// Pawns
	for (int i = 0; i < 8; i++)
	{
		fields[i][6].currentFigure = new Figure(Figure::Type::PAWN);
	}

	// Rooks
	fields[0][7].currentFigure = new Figure(Figure::Type::ROOK);
	fields[7][7].currentFigure = new Figure(Figure::Type::ROOK);

	// Knights
	fields[1][7].currentFigure = new Figure(Figure::Type::KNIGHT);
	fields[6][7].currentFigure = new Figure(Figure::Type::KNIGHT);

	// Bishops
	fields[2][7].currentFigure = new Figure(Figure::Type::BISHOP);
	fields[5][7].currentFigure = new Figure(Figure::Type::BISHOP);

	// Queen and King
	fields[3][7].currentFigure = new Figure(Figure::Type::QUEEN);
	fields[4][7].currentFigure = new Figure(Figure::Type::KING);
}