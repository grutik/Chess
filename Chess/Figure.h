#pragma once
#include "Sprite.h"

///
///  \brief Abstrakcyjna klasa figury szachowej. Definiuje wsp�lne cechy figur.
///
/// Dziedziczy z klasy Sprite, dzi�ki czemu mo�liwe jest okre�lenie fragmentu bitmapy dla danej figury
class Figure : public Sprite
{
public:
	///
	/// \brief Definicja typu reprezentuj�cego pojedynczy, mo�liwy ruch figury.
	///
	/// Technicznie, typ ten jest wska�nikiem na funkcj�, kt�ra w oparciu o wsp�rz�dne figury, zwraca jej nowe po�o�enie
	///
	typedef int*(*movement)(int x, int y);

	Figure(bool white);
	~Figure();
	
	///
	/// \brief Okre�la, czy figura jest bia�ego koloru
	///
	bool IsWhite();

	///
	/// \brief Okre�la, czy figury s� tego samego koloru
	///
	bool HasSameColor(Figure* figure);

	///
	/// \brief Okre�la, czy figury s� r�nego koloru
	///
	bool HasDifferentColor(Figure* figure);

	///
	/// \brief Okre�la, czy ruchy figury mog� by� okre�lone w spos�b rekursywny.
	///
	/// Je�eli parametr ten zwraca prawd�, to ruch figury mo�e by� okre�lony przez wi�cej ni� jedno wykonanie pojedynczej funkcji, okre�laj�ce jej ruch (pojedynczej funkcji z zestawu podstawowych ruch�w).
	///
	bool HasRecursiveMovement();

	///
	/// \brief Okre�la, czy definicje podstawowych ruch�w figury s� r�ne od ruch�w zwi�zanych z atakiem - dotyczy pionk�w.
	///
	bool HasSpecialAttackAbilities();


	///
	/// \brief Definiuje zestaw podstawowych ruch�w figury
	///
	movement* GetBasicMoves();

	///
	/// \brief Okre�la ilo�� podstawowych ruch�w figury
	///
	int GetBasicMovesCount();

	///
	/// \brief Definiuje zestaw ruch�w figury zwi�zanych z atakiem
	///
	movement* GetAttackMoves();

	///
	/// \brief Okre�la ilo�� ruch�w figury zwi�zanych z atakiem
	///
	int GetAttackMovesCount();

private:
	///
	/// \brief Inicjalizuje podstawowe ruchy figury
	///
	virtual void InitBasicMoves() = 0;

protected:
	bool _isWhite;
	bool _hasRecursiveMovement;
	bool _hasSpecialAttackAbilities;

	movement* _basicMoves;
	int _basicMovesCount;
	movement* _attackMoves;
	int _attackMovesCount;
};

