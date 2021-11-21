#pragma once
#include "Piece.h"
class Black_Pawn : Piece
{
public:
	Black_Pawn(int file, int rank);

	void Move1();

	void Move2();

	void AttackLeft();

	void AttackRight();
};

