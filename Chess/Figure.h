#pragma once

///
///  \brief Abstrakcyjna klasa figury szachowej. Definiuje wspólne cechy figur.
///
class Figure
{
public:
	///
	/// \brief Definicja typu reprezentuj¹cego pojedynczy, mo¿liwy ruch figury.
	///
	/// Technicznie, typ ten jest wskaŸnikiem na funkcjê, która w oparciu o wspó³rzêdne figury, zwraca jej nowe po³o¿enie
	///
	typedef int*(*movement)(int x, int y);

	Figure(bool white, int spriteXOffset);
	~Figure();
	
	///
	/// Zwraca przesuniêcie sprite'a na osi X
	///
	int GetSpriteOffset();

	///
	/// Okreœla, czy figura jest bia³ego koloru
	///
	bool IsWhite();

	///
	/// Okreœla, czy figury s¹ tego samego koloru
	///
	bool HasSameColor(Figure* figure);

	///
	/// Okreœla, czy figury s¹ ró¿nego koloru
	///
	bool HasDifferentColor(Figure* figure);

	///
	/// \brief Okreœla, czy ruchy figury mog¹ byæ okreœlone w sposób rekursywny.
	///
	/// Je¿eli parametr ten zwraca prawdê, to ruch figury mo¿e byæ okreœlony przez wiêcej ni¿ jedno wykonanie pojedynczej funkcji, okreœlaj¹ce jej ruch (pojedynczej funkcji z zestawu podstawowych ruchów).
	///
	bool HasRecursiveMovement();

	///
	/// Okreœla, czy definicje podstawowych ruchów figury s¹ ró¿ne od ruchów zwi¹zanych z atakiem - dotyczy pionków.
	///
	bool HasSpecialAttackAbilities();


	///
	/// Definiuje zestaw podstawowych ruchów figury
	///
	movement* GetBasicMoves();

	///
	/// Okreœla iloœæ podstawowych ruchów figury
	///
	int GetBasicMovesCount();

	///
	/// Definiuje zestaw ruchów figury zwi¹zanych z atakiem
	///
	movement* GetAttackMoves();

	///
	/// Okreœla iloœæ ruchów figury zwi¹zanych z atakiem
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

