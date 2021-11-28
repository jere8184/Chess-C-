#include "Knight.h"


bool Knight::ValidateKnightMove(int destFile, int destRank) {
	
	int fileDelta = destFile - FileIndex;
	int rankDelta = destRank - RankIndex;

	if (FileIndex + fileDelta > 7 || RankIndex + rankDelta > 7 || RankIndex + rankDelta < 0 || FileIndex + fileDelta < 0)
	{
	cout << "off the board" << endl;
	return false;
	}

	else if ((abs(fileDelta) != 2 || abs(rankDelta) != 1) && (abs(rankDelta) != 2 || abs(fileDelta) != 1)) {
		cout << "invalid Knight move" << endl;
		return false;
	}

	else {
		return true;
	}
}

void Knight::KnightMove(int destFile, int destRank) {
	if (ValidateKnightMove(destFile, destRank) == true) {
		Board::board[destFile][destRank].isOccupied ? Attack(destFile, destRank) : Move(destFile, destRank);
	}
}


void Knight::TryMove(int destFile, int destRank) {
	KnightMove(destFile, destRank);
}

Knight::Knight(int file, int rank, string colour)
	: Piece(file, rank, colour)
{
	this->Symbol = "N";
	this->Type = "Knight";
}