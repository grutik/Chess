#pragma once

#include "Field.h";

///
///  \brief Klasa reprezentuj�ca szachownic�. Odpowiada za przestrzeganie regu� gry.
///
class Board
{
public:
	///
	///  \brief Okre�la ilo�� p�l szachownicy
	///
	static const int numberOfFields = 8;

	Board();
	~Board();

	///
	///  \brief Obs�uguje zdarzenie wskazania danego pola
	///
	void OnFieldSelected(int x, int y);

	///
	///  \brief Zwraca pole o danych wsp�rz�dnych
	///
	Field* GetField(int x, int y);

	///
	///  \brief Okre�la, czy aktualny ruch nale�y do figur bia�ych
	///
	bool IsWhiteTurn();

private:
	Field* _selectedField;
	Field*** _fields;

	///
	///  \brief Tworzy szachownic�
	///
	void CreateFields();

	///
	///  \brief Tworzy i ustawia figury na planszy
	///
	void SetFigures();


	///
	///  \brief Zaznacza dane pole. Ustawia je jako aktualnie wybrane, aktywne.
	///
	void SelectField(Field* field);

	///
	///  \brief Odznacza wybrane pole
	///
	void ClearSelectedField();

	///
	///  \brief Okre�la, czy na szachownicy znajdue si� zaznaczone pole
	///
	bool HasSelectedField();


	///
	///  \brief Obs�uguje zdarzenie zwi�zane z pr�b� przestawienia figury na inne pole lub atak
	///
	void TryMoveFigure(Field* destinationField);

	///
	///  \brief Okre�la nast�pny krok figury w oparciu o jej funkcj� ruchu, jej po�o�enie oraz po�o�enie docelowe
	///
	void TryGetNextStep(int x, int y, Figure::movement movment, Field* destinationField);
	
	///
	///  \brief Przestawia figur� na wskazane pole
	///
	void MoveFigure(Field* destinationField);

	///
	///  \brief Zbija figur� na danym polu i zast�puje j� figur� z pola bie��cego
	///
	void BeatFigure(Field* destinationField);
	
	bool _isWhiteTurn;
	void SetOpponentTurn();
};

