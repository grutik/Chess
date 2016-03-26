#include "Board.h"



Board::Board()
{
	selectedField = nullptr;
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
	
	// White

	// Pawns
	for (int i = 0; i < 8; i++)
	{
		fields[i][6].currentFigure = new Figure(Figure::Type::PAWN, true);
	}

	// Rooks
	fields[0][7].currentFigure = new Figure(Figure::Type::ROOK, true);
	fields[7][7].currentFigure = new Figure(Figure::Type::ROOK, true);

	// Knights
	fields[1][7].currentFigure = new Figure(Figure::Type::KNIGHT, true);
	fields[6][7].currentFigure = new Figure(Figure::Type::KNIGHT, true);

	// Bishops
	fields[2][7].currentFigure = new Figure(Figure::Type::BISHOP, true);
	fields[5][7].currentFigure = new Figure(Figure::Type::BISHOP, true);

	// Queen and King
	fields[3][7].currentFigure = new Figure(Figure::Type::QUEEN, true);
	fields[4][7].currentFigure = new Figure(Figure::Type::KING, true);

	// Black
	// Pawns
	for (int i = 0; i < 8; i++)
	{
		fields[i][1].currentFigure = new Figure(Figure::Type::PAWN, false);
	}

	// Rooks
	fields[0][0].currentFigure = new Figure(Figure::Type::ROOK, false);
	fields[7][0].currentFigure = new Figure(Figure::Type::ROOK, false);

	// Knights
	fields[1][0].currentFigure = new Figure(Figure::Type::KNIGHT, false);
	fields[6][0].currentFigure = new Figure(Figure::Type::KNIGHT, false);

	// Bishops
	fields[2][0].currentFigure = new Figure(Figure::Type::BISHOP, false);
	fields[5][0].currentFigure = new Figure(Figure::Type::BISHOP, false);

	// Queen and King
	fields[3][0].currentFigure = new Figure(Figure::Type::QUEEN, false);
	fields[4][0].currentFigure = new Figure(Figure::Type::KING, false);

}

void Board::MoveFigure(Field* destinationField) {
	if (destinationField->currentFigure == nullptr) {
		Figure* sourceFig = selectedField->currentFigure;
		
		destinationField->currentFigure = sourceFig;
		destinationField->Unselect();
		
		selectedField->currentFigure = nullptr;
		selectedField->Unselect();
		selectedField = nullptr;
	}
}