#pragma once
#include "Piece.h"
class Bishop : Piece
{
public:
	Bishop(int file, int rank, string colour);

	void BishopDiagMove(int DestFile, int DestRank);

	void BishopDiagAttack(int DestFile, int DestRank);

	void TryMove(int DestFile, int DestRank);
};

