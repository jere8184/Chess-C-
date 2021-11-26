#pragma once
#include "Piece.h"
class Black_Pawn : Piece
{
public:
	Black_Pawn(int file, int rank);

	void PawnMove(int destFile, int destRank);

	void PawnAttack(int destFile, int destRank);

	void TryMove(int destFile, int destRank);

	bool ValidatePawnMove(int destFile, int destRank);

	bool ValidatePawnAttack(int destFile, int destRank);
};

