#pragma once
#include "Sprite.h"

///
///  \brief Abstrakcyjna klasa figury szachowej. Definiuje wspólne cechy figur.
///
/// Dziedziczy z klasy Sprite, dziêki czemu mo¿liwe jest okreœlenie fragmentu bitmapy dla danej figury
class Figure : public Sprite
{
public:
	///
	/// \brief Definicja typu reprezentuj¹cego pojedynczy, mo¿liwy ruch figury.
	///
	/// Technicznie, typ ten jest wskaŸnikiem na funkcjê, która w oparciu o wspó³rzêdne figury, zwraca jej nowe po³o¿enie
	///
	typedef int*(*movement)(int x, int y);

	Figure(bool white);
	~Figure();
	
	///
	/// \brief Okreœla, czy figura jest bia³ego koloru
	///
	bool IsWhite();

	///
	/// \brief Okreœla, czy figury s¹ tego samego koloru
	///
	bool HasSameColor(Figure* figure);

	///
	/// \brief Okreœla, czy figury s¹ ró¿nego koloru
	///
	bool HasDifferentColor(Figure* figure);

	///
	/// \brief Okreœla, czy ruchy figury mog¹ byæ okreœlone w sposób rekursywny.
	///
	/// Je¿eli parametr ten zwraca prawdê, to ruch figury mo¿e byæ okreœlony przez wiêcej ni¿ jedno wykonanie pojedynczej funkcji, okreœlaj¹ce jej ruch (pojedynczej funkcji z zestawu podstawowych ruchów).
	///
	bool HasRecursiveMovement();

	///
	/// \brief Okreœla, czy definicje podstawowych ruchów figury s¹ ró¿ne od ruchów zwi¹zanych z atakiem - dotyczy pionków.
	///
	bool HasSpecialAttackAbilities();


	///
	/// \brief Definiuje zestaw podstawowych ruchów figury
	///
	movement* GetBasicMoves();

	///
	/// \brief Okreœla iloœæ podstawowych ruchów figury
	///
	int GetBasicMovesCount();

	///
	/// \brief Definiuje zestaw ruchów figury zwi¹zanych z atakiem
	///
	movement* GetAttackMoves();

	///
	/// \brief Okreœla iloœæ ruchów figury zwi¹zanych z atakiem
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

