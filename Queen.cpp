#include "Queen.h"


Queen::Queen(int file, int rank, string colour)
	: Piece(file, rank, colour)
{
	SetSymbol("Q");
	SetType("Queen");
}

bool Queen::ValidateMove(int destFile, int destRank)
{
	int fileDelta = GetFileDelta(destFile);
	int rankDelta = GetRankDelta(destRank);

	if(!IsDiaganolMove(fileDelta, rankDelta) || !IsStraightMove(fileDelta, rankDelta))
	{
		cout << "invalid queen move\n";
		return false;
	}
	return true;
}
