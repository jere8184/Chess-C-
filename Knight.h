#pragma once

#include "Piece.h"
class Knight : Piece
{
public:
	Knight(int file, int rank, string colour);

	void KnightMove(int DestFile, int DestRank);

	void KnightAttack(int DestFile, int DestRank);

	bool ValidateKnightMove(int DestFile, int DestRank);

	bool ValidateKnightAttack(int DestFile, int DestRank);

	void TryMove(int DestFile, int DestRank);
};

