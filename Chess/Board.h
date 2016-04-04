#pragma once

#include "Field.h";

///
///  \brief Klasa reprezentuj¹ca szachownicê
///
class Board
{
public:
	static const int numberOfFields = 8;
	Field* selectedField;
	Field*** fields;
	
	Board();
	~Board();

	void CreateFields();
	void SetFigures();
	void TryMoveFigure(Field* destinationField);

	bool IsWhiteTurn();

private:
	void MoveFigure(Field* destinationField);
	void BeatFigure(Field* destinationField);
	void TryGetNextStep(int x, int y, Figure::movement movment, Field* destinationField);

	bool _isWhiteTurn;
	void SetOpponentTurn();
};

