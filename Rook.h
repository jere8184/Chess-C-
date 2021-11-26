#pragma once
#include "Piece.h"
class Rook : Piece
{
public:
	Rook(int file, int rank, string colour);

	void TryMove(int DestFile, int DestRank);

	void RookStraightMove(int DestFile, int DestRank);

	void RookStraightAttack(int DestFile, int DestRank);
};

