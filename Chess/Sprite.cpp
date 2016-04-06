#include "Sprite.h"



Sprite::Sprite()
{
}


Sprite::~Sprite()
{
}

int Sprite::GetSpriteOffset()
{
	return _spriteOffset;
}

void Sprite::SetSpriteOffset(int spriteOffset)
{
	_spriteOffset = spriteOffset;
}
