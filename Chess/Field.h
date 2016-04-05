#pragma once

#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

///
///  \brief Klasa reprezentuj�ca pojedyncze pole szachownicy
///
class Field
{
public:

	Field(int x, int y, int color);
	~Field();

	///
	///  \brief Zwraca wsp�rz�dn� x na szachownicy
	///
	int GetX();

	///
	///  \brief Zwraca wsp�rz�dn� y na szachownicy
	///
	int GetY();

	///
	///  \brief Zwraca kolor pola szachownicy (ciemny/jasny)
	///
	int GetColor();


	///
	///  \brief Okre�la, czy na polu znajduje si� figura
	///
	bool HasFigure();

	///
	///  \brief Zwraca figur� znajduj�c� si� na polu
	///
	Figure* GetFigure();

	///
	///  \brief Ustawia figur� na tym polu
	///
	void SetFigure(Figure* figure);

	///
	///  \brief Usuwa figur� z pola
	///
	void RemoveFigure();
	

	///
	///  \brief Okre�la, czy pole jest zaznaczone
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

