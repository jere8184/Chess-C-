#pragma once
#include "Piece.h"
class Bishop : Piece
{
public:
	Bishop(int file, int rank, string colour);
	bool ValidateMove(int destFile, int destRank);
};

