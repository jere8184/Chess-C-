#include "Bishop.h"

Bishop::Bishop(int file, int rank, string colour)
	: Piece(file, rank, colour)
{
	SetSymbol("B");
	SetType("Bishop");
	IsWhite() ? SetTexture("white_bishop.png") : SetTexture("black_bishop.png");
}

bool Bishop::ValidateMove(int destFile, int destRank)
{
	int fileDelta = GetFileDelta(destFile);
	int rankDelta = GetRankDelta(destRank);
	if(!IsDiaganolMove(fileDelta, rankDelta))
	{
		cout << "invalid bishiop move\n";
		return false;
	}
	return true;
}