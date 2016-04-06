#pragma once

///
///  \brief Klasa umo¿liwiaj¹ca zwi¹zanie obrazka z danym obiektem
///
/// W tym projekcie wystarczaj¹cym parametrem jest przesuniêcie X na bitmapie zawieraj¹cej wszystkie figury szachowe

class Sprite
{
public:
	Sprite();
	~Sprite();

	///
	/// \brief Zwraca przesuniêcie x na bitmapie figur szachowych
	///
	int GetSpriteOffset();

	///
	/// \brief Ustawia przesuniêcie x na bitmapie figur szachowych
	///
	void SetSpriteOffset(int spriteOffset);
protected:
	int _spriteOffset;
};

