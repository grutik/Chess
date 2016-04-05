#pragma once

///
///  \brief Abstrakcyjna klasa figury szachowej. Definiuje wsp�lne cechy figur.
///
class Figure
{
public:
	///
	/// \brief Definicja typu reprezentuj�cego pojedynczy, mo�liwy ruch figury.
	///
	/// Technicznie, typ ten jest wska�nikiem na funkcj�, kt�ra w oparciu o wsp�rz�dne figury, zwraca jej nowe po�o�enie
	///
	typedef int*(*movement)(int x, int y);

	Figure(bool white, int spriteXOffset);
	~Figure();
	
	///
	/// Zwraca przesuni�cie sprite'a na osi X
	///
	int GetSpriteOffset();

	///
	/// Okre�la, czy figura jest bia�ego koloru
	///
	bool IsWhite();

	///
	/// Okre�la, czy figury s� tego samego koloru
	///
	bool HasSameColor(Figure* figure);

	///
	/// Okre�la, czy figury s� r�nego koloru
	///
	bool HasDifferentColor(Figure* figure);

	///
	/// \brief Okre�la, czy ruchy figury mog� by� okre�lone w spos�b rekursywny.
	///
	/// Je�eli parametr ten zwraca prawd�, to ruch figury mo�e by� okre�lony przez wi�cej ni� jedno wykonanie pojedynczej funkcji, okre�laj�ce jej ruch (pojedynczej funkcji z zestawu podstawowych ruch�w).
	///
	bool HasRecursiveMovement();

	///
	/// Okre�la, czy definicje podstawowych ruch�w figury s� r�ne od ruch�w zwi�zanych z atakiem - dotyczy pionk�w.
	///
	bool HasSpecialAttackAbilities();


	///
	/// Definiuje zestaw podstawowych ruch�w figury
	///
	movement* GetBasicMoves();

	///
	/// Okre�la ilo�� podstawowych ruch�w figury
	///
	int GetBasicMovesCount();

	///
	/// Definiuje zestaw ruch�w figury zwi�zanych z atakiem
	///
	movement* GetAttackMoves();

	///
	/// Okre�la ilo�� ruch�w figury zwi�zanych z atakiem
	///
	int GetAttackMovesCount();

private:
	virtual void InitBasicMoves() = 0;

protected:
	int _spriteOffset;
	bool _isWhite;
	bool _hasRecursiveMovement;
	bool _hasSpecialAttackAbilities;

	movement* _basicMoves;
	int _basicMovesCount;
	movement* _attackMoves;
	int _attackMovesCount;
};

