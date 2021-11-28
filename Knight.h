#pragma once

#include "Piece.h"
class Knight : Piece
{
public:
	Knight(int file, int rank, string colour);

	void KnightMove(int destFile, int destRank);

	void KnightAttack(int destFile, int destRank);

	bool ValidateKnightMove(int destFile, int destRank);

	bool ValidateKnightAttack(int destFile, int destRank);

	void TryMove(int destFile, int destRank);
};

