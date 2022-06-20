#include "Knight.h"


bool Knight::ValidateMove(int destFile, int destRank) {
	
	int fileDelta = GetFileDelta(destFile);
	int rankDelta = GetRankDelta(destRank);

	if(!StandardChecks(fileDelta, rankDelta))
	{
		return false;
	}
	if ((abs(fileDelta) != 2 || abs(rankDelta) != 1) && (abs(rankDelta) != 2 || abs(fileDelta) != 1)) {
		cout << "invalid Knight move" << endl;
		return false;
	}
	else 
	{
		return true;
	}
}

Knight::Knight(int file, int rank, string colour)
	: Piece(file, rank, colour)
{
	SetSymbol("N");
	this->SetType("Knight");
}