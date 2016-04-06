#include "Board.h"


Field * Board::GetField(int x, int y)
{
	return _fields[x][y];
}

void Board::SelectField(Field * field)
{
	_selectedField = field;
	_selectedField->Select();
}

void Board::ClearSelectedField()
{
	_selectedField->Unselect();
	_selectedField = nullptr;
}

void Board::OnFieldSelected(int x, int y)
{
	Field* currentField = GetField(x, y);

	if (this->HasSelectedField() || currentField->HasFigure()) // Obs³uguj, jeœli jakaœ figura jest ju¿ wybrana LUB podjêto próbê zaznaczenia figury (zabezpiecznie przed zaznaczeniem pustego pola)
		if (!this->HasSelectedField()) { // Gdy ¿adne pole nie by³o wczeœniej wybrane
			if (this->IsWhiteTurn() == currentField->GetFigure()->IsWhite()) { // Wybierz figurê, jeœli jej kolor jest zgodny z kolorem bie¿¹cego gracza
				this->SelectField(currentField);
			}
		}
		else {
			if (_selectedField == currentField) { // Gdy klikniêto w to samo pole drugi raz
				this->ClearSelectedField();
			}
			else
			{
				// Gdy jedno z pól by³o wczeœniej zaznaczone, a teraz klikniêto w inne
				this->TryMoveFigure(currentField);
			}
		}
}

bool Board::HasSelectedField()
{
	return _selectedField != nullptr;
}

Board::Board()
{
	_selectedField = nullptr;
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

	_fields = new Field**[numberOfFields];
	for (int i = 0; i < numberOfFields; i++)
	{

		_fields[i] = new Field*[numberOfFields];
		for (int j = 0; j < numberOfFields; j++)
		{
			int color = draw_white ? 1 : 0;
			_fields[i][j] = new Field(i, j, color);

			draw_white = !draw_white;
		}
		draw_white = !draw_white;
	}
}

void Board::SetFigures() {

	//** White **//
	bool isWhite = true;

	// Pawns
	for (int i = 0; i < 8; i++)
	{
		_fields[i][6]->SetFigure(new Pawn(isWhite));
		_fields[i][6]->GetFigure()->SetSpriteOffset(0);
	}

	// Rooks
	_fields[0][7]->SetFigure(new Rook(isWhite));
	_fields[0][7]->GetFigure()->SetSpriteOffset(3);

	_fields[7][7]->SetFigure(new Rook(isWhite));
	_fields[7][7]->GetFigure()->SetSpriteOffset(3);

	// Knights	 
	_fields[1][7]->SetFigure(new Knight(isWhite));
	_fields[1][7]->GetFigure()->SetSpriteOffset(1);

	_fields[6][7]->SetFigure(new Knight(isWhite));
	_fields[6][7]->GetFigure()->SetSpriteOffset(1);

	// Bishops	  
	_fields[2][7]->SetFigure(new Bishop(isWhite));
	_fields[2][7]->GetFigure()->SetSpriteOffset(2);

	_fields[5][7]->SetFigure(new Bishop(isWhite));
	_fields[5][7]->GetFigure()->SetSpriteOffset(2);

	// Queen and King
	_fields[3][7]->SetFigure(new Queen(isWhite));
	_fields[3][7]->GetFigure()->SetSpriteOffset(4);

	_fields[4][7]->SetFigure(new King(isWhite));
	_fields[4][7]->GetFigure()->SetSpriteOffset(5);


	//** Black **//
	isWhite = false;

	// Pawns
	for (int i = 0; i < 8; i++)
	{
		_fields[i][1]->SetFigure(new Pawn(isWhite));
		_fields[i][1]->GetFigure()->SetSpriteOffset(0);
	}

	// Rooks
	_fields[0][0]->SetFigure(new Rook(isWhite));
	_fields[0][0]->GetFigure()->SetSpriteOffset(3);

	_fields[7][0]->SetFigure(new Rook(isWhite));
	_fields[7][0]->GetFigure()->SetSpriteOffset(3);

	// Knights
	_fields[1][0]->SetFigure(new Knight(isWhite));
	_fields[1][0]->GetFigure()->SetSpriteOffset(1);

	_fields[6][0]->SetFigure(new Knight(isWhite));
	_fields[6][0]->GetFigure()->SetSpriteOffset(1);


	// Bishops
	_fields[2][0]->SetFigure(new Bishop(isWhite));
	_fields[2][0]->GetFigure()->SetSpriteOffset(2);

	_fields[5][0]->SetFigure(new Bishop(isWhite));
	_fields[5][0]->GetFigure()->SetSpriteOffset(2);

	// Queen and King
	_fields[3][0]->SetFigure(new Queen(isWhite));
	_fields[3][0]->GetFigure()->SetSpriteOffset(4);

	_fields[4][0]->SetFigure(new King(isWhite));
	_fields[4][0]->GetFigure()->SetSpriteOffset(5);

}


void Board::TryMoveFigure(Field* destinationField) {

	Figure* currentFig = _selectedField->GetFigure();

	Figure::movement* moves;
	int movesCount;

	int isAttack = destinationField->HasFigure() && currentFig->HasDifferentColor(destinationField->GetFigure());

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
		TryGetNextStep(_selectedField->GetX(), _selectedField->GetY(), moves[i], destinationField);

		if (_selectedField == nullptr)
			break;
	}
}

void Board::TryGetNextStep(int x, int y, Figure::movement movment, Field* destinationField) {

	int* nextCords = movment(x, y);

	int nextX = nextCords[0];
	int nextY = nextCords[1];

	if (nextX >= 0 && nextX < 8 && nextY >= 0 && nextY < 8) {

		Field* currentField = _fields[nextX][nextY];

		if (nextX == destinationField->GetX() && nextY == destinationField->GetY()) {
			if (!destinationField->HasFigure())
			{
				MoveFigure(destinationField);
			}
			else {
				if (destinationField->GetFigure()->HasDifferentColor(_selectedField->GetFigure()))
				{
					BeatFigure(destinationField);
				}
			}
		}
		else
			if (!currentField->HasFigure() && _selectedField->GetFigure()->HasRecursiveMovement())
				TryGetNextStep(nextCords[0], nextCords[1], movment, destinationField);

	}
	else return;
}


void Board::MoveFigure(Field* destination) {
	Figure* sourceFig = _selectedField->GetFigure();
	destination->SetFigure(sourceFig);
	_selectedField->RemoveFigure();

	destination->Unselect();
	_selectedField->Unselect();
	_selectedField = nullptr;

	SetOpponentTurn();
}

void Board::BeatFigure(Field* destination) {
	destination->SetFigure(_selectedField->GetFigure());
	_selectedField->RemoveFigure();

	destination->Unselect();
	_selectedField->Unselect();
	_selectedField = nullptr;

	SetOpponentTurn();
}

void Board::SetOpponentTurn() {
	_isWhiteTurn = !_isWhiteTurn;
}