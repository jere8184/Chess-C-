#pragma once
#include "Piece.h"
#include <string>

class Queen : Piece
{
public:
	Queen(int file, int rank, string colour);

	void QueenDiagMove(int DestFile, int DestRank);

	void QueenStraightMove(int DestFile, int DestRank);

	void QueenDiagAttack(int DestFile, int DestRank);

	void QueenStraightAttack(int DestFile, int DestRank);

	void TryMove(int DestFile, int DestRank);
};

