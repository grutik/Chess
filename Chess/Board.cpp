#include "Board.h"



Board::Board()
{
	selectedField = nullptr;
	CreateFields();
	SetFigures();
	_isWhiteTurn = true;
}

Board::~Board()
{
}

bool Board::IsWhiteTurn()
{
	return _isWhiteTurn;
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
		fields[i][6]->SetFigure(new Pawn(isWhite, 0));
	}

	// Rooks
	fields[0][7]->SetFigure(new Rook(isWhite, 3));
	fields[7][7]->SetFigure(new Rook(isWhite, 3));

	// Knights	 
	fields[1][7]->SetFigure(new Knight(isWhite, 1));
	fields[6][7]->SetFigure(new Knight(isWhite, 1));

	// Bishops	  
	fields[2][7]->SetFigure(new Bishop(isWhite, 2));
	fields[5][7]->SetFigure(new Bishop(isWhite, 2));

	// Queen and King
	fields[3][7]->SetFigure(new Queen(isWhite, 4));
	fields[4][7]->SetFigure(new King(isWhite, 5));

	// Black
	isWhite = false;

	// Pawns
	for (int i = 0; i < 8; i++)
	{
		fields[i][1]->SetFigure(new Pawn(isWhite, 0));
	}

	// Rooks
	fields[0][0]->SetFigure(new Rook(isWhite, 3));
	fields[7][0]->SetFigure(new Rook(isWhite, 3));

	// Knights
	fields[1][0]->SetFigure(new Knight(isWhite, 1));
	fields[6][0]->SetFigure(new Knight(isWhite, 1));

	// bishops
	fields[2][0]->SetFigure(new Bishop(isWhite, 2));
	fields[5][0]->SetFigure(new Bishop(isWhite, 2));

	// queen and king
	fields[3][0]->SetFigure(new Queen(isWhite, 4));
	fields[4][0]->SetFigure(new King(isWhite, 5));

}


void Board::TryMoveFigure(Field* destinationField) {

	Figure* currentFig = selectedField->GetFigure();

	Figure::movement* moves;
	int movesCount;

	int isAttack = destinationField->HasFigure() && currentFig->IsWhite() != destinationField->GetFigure()->IsWhite();

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
		TryGetNextStep(selectedField->GetX(), selectedField->GetY(), moves[i], destinationField);

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

		if (nextX == destinationField->GetX() && nextY == destinationField->GetY()) {
			if (!destinationField->HasFigure())
			{
				MoveFigure(destinationField);
			}
			else {
				if (destinationField->GetFigure()->IsWhite() == selectedField->GetFigure()->IsWhite())
					;//do nothing
				else {
					BeatFigure(destinationField);
				}
			}
		}
		else
			if (!currentField->HasFigure() && selectedField->GetFigure()->HasRecursiveMovement())
				TryGetNextStep(nextCords[0], nextCords[1], movment, destinationField);

	}
	else return;
}


void Board::MoveFigure(Field* destination) {
	Figure* sourceFig = selectedField->GetFigure();
	destination->SetFigure(sourceFig);
	selectedField->RemoveFigure();

	destination->Unselect();
	selectedField->Unselect();
	selectedField = nullptr;

	SetOpponentTurn();
}

void Board::BeatFigure(Field* destination) {
	destination->SetFigure(selectedField->GetFigure());
	selectedField->RemoveFigure();

	destination->Unselect();
	selectedField->Unselect();
	selectedField = nullptr;

	SetOpponentTurn();
}

void Board::SetOpponentTurn() {
	_isWhiteTurn = !_isWhiteTurn;
}