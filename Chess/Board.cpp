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

	fields = new Field**[numberOfFields];
	for (int i = 0; i < Board::numberOfFields; i++)
	{

		fields[i] = new Field*[numberOfFields];
		for (int j = 0; j < Board::numberOfFields; j++)
		{
			int color = draw_white ? 1 : 0;
			fields[i][j] = new Field(i, j, color);

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
		fields[i][6]->fig = new Pawn(isWhite, 0);
	}

	// Rooks
	fields[0][7]->fig = new Rook(isWhite, 3);
	fields[7][7]->fig = new Rook(isWhite, 3);

	// Knights
	fields[1][7]->fig = new Knight(isWhite, 1);
	fields[6][7]->fig = new Knight(isWhite, 1);

	// Bishops
	fields[2][7]->fig = new Bishop(isWhite, 2);
	fields[5][7]->fig = new Bishop(isWhite, 2);

	// Queen and King
	fields[3][7]->fig = new Queen(isWhite, 4);
	fields[4][7]->fig = new King(isWhite, 5);

	// Black
	isWhite = false;

	// Pawns
	for (int i = 0; i < 8; i++)
	{
		fields[i][1]->fig = new Pawn(isWhite, 0);
	}

	// Rooks
	fields[0][0]->fig = new Rook(isWhite, 3);
	fields[7][0]->fig = new Rook(isWhite, 3);

	// Knights
	fields[1][0]->fig = new Knight(isWhite, 1);
	fields[6][0]->fig = new Knight(isWhite, 1);

	// bishops
	fields[2][0]->fig = new Bishop(isWhite, 2);
	fields[5][0]->fig = new Bishop(isWhite, 2);

	// queen and king
	fields[3][0]->fig = new Queen(isWhite, 4);
	fields[4][0]->fig = new King(isWhite, 5);

}

void Board::TryMoveFigure(Field* destinationField) {

	Figure* currentFig = selectedField->fig;

	Figure::movement* moves;
	int movesCount;

	int isAttack = destinationField->fig != nullptr && currentFig->IsWhite() != destinationField->fig->IsWhite();

	if (isAttack && currentFig->HasSpecialAttackAbilities()) {
		moves = currentFig->GetAttackMoves();
		movesCount = currentFig->GetAttackMovesCount();
	}
	else
	{
		moves = currentFig->GetBasicMoves();
		movesCount = currentFig->GetBasicMovesCount();
	}

	for (int i = 0; i < movesCount; i++)
	{
		TryGetNextStep(selectedField->x, selectedField->y, moves[i], destinationField);

		if (selectedField == nullptr)
			break;
	}
}


void Board::TryGetNextStep(int x, int y, Figure::movement movment, Field* destinationField) {

	int* nextCords = movment(x, y);

	int nextX = nextCords[0];
	int nextY = nextCords[1];

	if (nextX >= 0 && nextX < 8 && nextY >= 0 && nextY < 8) {

		Field* currentField = fields[nextX][nextY];

		if (nextX == destinationField->x && nextY == destinationField->y) {
			if (destinationField->fig == nullptr)
			{
				MoveFigure(destinationField);
			}
			else {
				if (destinationField->fig->IsWhite() == selectedField->fig->IsWhite())
					;//do nothing
				else {
					BeatFigure(destinationField);
				}
			}
		}
		else
			if (currentField->fig == nullptr && selectedField->fig->HasRecursiveMovement())
				TryGetNextStep(nextCords[0], nextCords[1], movment, destinationField);

	}
	else return;
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