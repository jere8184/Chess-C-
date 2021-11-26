#pragma once
#include "Piece.h"
class King : Piece
{
public:
	King(int file, int rank, string colour);

	void KingDiagMove(int DestFile, int DestRank);

	void KingStraightMove(int DestFile, int DestRank);

	void KingDiagAttack(int DestFile, int DestRank);

	void KingStraightAttack(int DestFile, int DestRank);

	bool ValidateKingMove(int fileDelta, int rankDelta);

	void TryMove(int DestFile, int DestRank);
};

