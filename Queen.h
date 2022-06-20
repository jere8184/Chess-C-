#pragma once
#include "Piece.h"

class Queen : Piece
{
public:
	Queen(int file, int rank, string colour);
	bool ValidateMove(int DestFile, int DestRank);
};

