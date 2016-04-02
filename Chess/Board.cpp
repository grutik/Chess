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
	bool isWhite = true;

	// Pawns
	for (int i = 0; i < 8; i++)
	{
		fields[i][6].fig = new Pawn(isWhite);
	}

	// Rooks
	fields[0][7].fig = new Rook(isWhite);
	fields[7][7].fig = new Rook(isWhite);

	// Knights
	fields[1][7].fig = new Knight(isWhite);
	fields[6][7].fig = new Knight(isWhite);

	//// Bishops
	//fields[2][7].currentFigure = new Figure(Figure::Type::BISHOP, isWhite);
	//fields[5][7].currentFigure = new Figure(Figure::Type::BISHOP, isWhite);

	//// Queen and King
	//fields[3][7].currentFigure = new Figure(Figure::Type::QUEEN, isWhite);
	//fields[4][7].currentFigure = new Figure(Figure::Type::KING, isWhite);

	// Black
	isWhite = false;

	// Pawns
	for (int i = 0; i < 8; i++)
	{
		fields[i][1].fig = new Pawn(isWhite);
	}

	// Rooks
	fields[0][0].fig = new Rook(isWhite);
	fields[7][0].fig = new Rook(isWhite);

	// Knights
	fields[1][0].fig = new Knight(isWhite);
	fields[6][0].fig = new Knight(isWhite);

	//// Bishops
	//fields[2][0].currentFigure = new Figure(Figure::Type::BISHOP, isWhite);
	//fields[5][0].currentFigure = new Figure(Figure::Type::BISHOP, isWhite);

	//// Queen and King
	//fields[3][0].currentFigure = new Figure(Figure::Type::QUEEN, isWhite);
	//fields[4][0].currentFigure = new Figure(Figure::Type::KING, isWhite);

}

void Board::TryMoveFigure(Field* destinationField) {

	Figure* currentFig = selectedField->fig;

	if (destinationField->fig == nullptr) {
		// Check if move is available for specified figure

		Figure::movement* basicMoves = currentFig->basicMoves;
		for (int i = 0; i < currentFig->basicMovesCount; i++)
		{
			int* result = basicMoves[i](selectedField->x, selectedField->y);

			if (destinationField->x == result[0] && destinationField->y == result[1]) {
				MoveFigure(destinationField);
				break;
			}
		}
	}
	else {
		if (currentFig->white == destinationField->fig->white) {
			// Do nothing - the destination figure is of the same colour
		}
		else
		{
			Figure::movement* attackMoves;
			int attackMovesCount;

			if (currentFig->hasSpecialAttackAbilities) {
				attackMoves = currentFig->attackMoves;
				attackMovesCount = currentFig->attackMovesCount;
			}
			else
			{
				attackMoves = currentFig->basicMoves;
				attackMovesCount = currentFig->basicMovesCount;
			}


			for (int i = 0; i < attackMovesCount; i++)
			{
				int* result = attackMoves[i](selectedField->x, selectedField->y);

				if (destinationField->x == result[0] && destinationField->y == result[1]) {
					BeatFigure(destinationField);
					break;
				}
			}
		}
	}
}

void Board::MoveFigure(Field* destination) {
	Figure* sourceFig = selectedField->fig;
	destination->fig = sourceFig;
	selectedField->fig = nullptr;

	destination->Unselect();
	selectedField->Unselect();
	selectedField = nullptr;
}

void Board::BeatFigure(Field* destination) {
	destination->fig = selectedField->fig;
	selectedField->fig = nullptr;

	destination->Unselect();
	selectedField->Unselect();
	selectedField = nullptr;
}