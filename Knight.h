#pragma once

#include "Piece.h"
class Knight : Piece
{
public:
	Knight(int file, int rank, string colour);

	void KnightMove(int DestFile, int DestRank);

	void KnightAttack(int DestFile, int DestRank);

	bool ValidateKnightMove(int fileDelta, int rankDelta);

	bool ValidateKnightAttack(int fileDelta, int rankDelta);
};

