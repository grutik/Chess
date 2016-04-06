#pragma once

///
///  \brief Klasa umo�liwiaj�ca zwi�zanie obrazka z danym obiektem
///
/// W tym projekcie wystarczaj�cym parametrem jest przesuni�cie X na bitmapie zawieraj�cej wszystkie figury szachowe

class Sprite
{
public:
	Sprite();
	~Sprite();

	///
	/// \brief Zwraca przesuni�cie x na bitmapie figur szachowych
	///
	int GetSpriteOffset();

	///
	/// \brief Ustawia przesuni�cie x na bitmapie figur szachowych
	///
	void SetSpriteOffset(int spriteOffset);
protected:
	int _spriteOffset;
};

