#pragma once

#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

///
///  \brief Klasa reprezentuj¹ca pojedyncze pole szachownicy
///
class Field
{
public:

	Field(int x, int y, int color);
	~Field();

	///
	///  \brief Zwraca wspó³rzêdn¹ x na szachownicy
	///
	int GetX();

	///
	///  \brief Zwraca wspó³rzêdn¹ y na szachownicy
	///
	int GetY();

	///
	///  \brief Zwraca kolor pola szachownicy (ciemny/jasny)
	///
	int GetColor();


	///
	///  \brief Okreœla, czy na polu znajduje siê figura
	///
	bool HasFigure();

	///
	///  \brief Zwraca figurê znajduj¹c¹ siê na polu
	///
	Figure* GetFigure();

	///
	///  \brief Ustawia figurê na tym polu
	///
	void SetFigure(Figure* figure);

	///
	///  \brief Usuwa figurê z pola
	///
	void RemoveFigure();
	

	///
	///  \brief Okreœla, czy pole jest zaznaczone
	///
	int IsSelected();

	///
	///  \brief Zaznacza pole
	///
	void Select();

	///
	///  \brief Odznacza pole
	///
	void Unselect();

private:
	int _x;
	int _y;
	int _color;
	bool _selected;
	Figure* _fig;
};

