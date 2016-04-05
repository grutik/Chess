#pragma once

#include "Field.h";

///
///  \brief Klasa reprezentuj¹ca szachownicê. Odpowiada za przestrzeganie regu³ gry.
///
class Board
{
public:
	///
	///  \brief Okreœla iloœæ pól szachownicy
	///
	static const int numberOfFields = 8;

	Board();
	~Board();

	///
	///  \brief Obs³uguje zdarzenie wskazania danego pola
	///
	void OnFieldSelected(int x, int y);

	///
	///  \brief Zwraca pole o danych wspó³rzêdnych
	///
	Field* GetField(int x, int y);

	///
	///  \brief Okreœla, czy aktualny ruch nale¿y do figur bia³ych
	///
	bool IsWhiteTurn();

private:
	Field* _selectedField;
	Field*** _fields;

	///
	///  \brief Tworzy szachownicê
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
	///  \brief Okreœla, czy na szachownicy znajdue siê zaznaczone pole
	///
	bool HasSelectedField();


	///
	///  \brief Obs³uguje zdarzenie zwi¹zane z prób¹ przestawienia figury na inne pole lub atak
	///
	void TryMoveFigure(Field* destinationField);

	///
	///  \brief Okreœla nastêpny krok figury w oparciu o jej funkcjê ruchu, jej po³o¿enie oraz po³o¿enie docelowe
	///
	void TryGetNextStep(int x, int y, Figure::movement movment, Field* destinationField);
	
	///
	///  \brief Przestawia figurê na wskazane pole
	///
	void MoveFigure(Field* destinationField);

	///
	///  \brief Zbija figurê na danym polu i zastêpuje j¹ figurê z pola bie¿¹cego
	///
	void BeatFigure(Field* destinationField);
	
	bool _isWhiteTurn;
	void SetOpponentTurn();
};

