#pragma once
#include "Piece.h"
class Rook : Piece
{
public:
	Rook(int file, int rank, string colour);
	bool ValidateMove(int destFile, int destRank);
};

