#pragma once
#include "Piece.h"
class Pawn : Piece
{
public:
	Pawn(int file, int rank, string colour);

	void PawnMove(int destFile, int destRank);

	void PawnAttack(int destFile, int destRank);

	void TryMove(int destFile, int destRank);

	bool ValidateMove(int destFile, int destRank);

	bool ValidateAttack(int destFile, int destRank);
};

