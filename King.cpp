#include "King.h"

King::King(int file, int rank, string colour)
	: Piece(file, rank, colour)
{
	SetSymbol("K");
	this->Type = "King";
}

bool King::ValidateMove(int destFile, int destRank)
{
	int fileDelta = GetFileDelta(destFile);
	int rankDelta = GetRankDelta(destRank);

	if(abs(fileDelta) > 1 || abs(rankDelta) > 1)
	{
		cout << "invalid king move\n";
		return false;
	}
	return true;
}
