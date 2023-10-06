#pragma once
#include "Piece.h"
class King : Piece
{
public:
	King(int file, int rank, string colour);

	bool ValidateMove(int destFile, int destRank);
};

