#pragma once
#include "Figure.h"

///
///  \brief Klasa reprezentuj¹ca figurê króla
///
class King : public Figure
{
public:
	King(bool isWhite, int spriteXOffset);
	~King();
private:
	void InitBasicMoves();
};

