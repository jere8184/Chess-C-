#include "Knight.h"


bool Knight::ValidateKnightMove(int fileDelta, int rankDelta) {
	
	int destFile = FileIndex + fileDelta;
	int destRank = RankIndex + rankDelta;

	fileDelta = fileDelta * 1;
	rankDelta = rankDelta * 1;


	if (FileIndex + fileDelta > 7 || RankIndex + rankDelta > 7 || RankIndex + rankDelta < 0 || FileIndex + fileDelta < 0)
	{
	cout << "off the board" << endl;
	return false;
	}

	else if ((fileDelta != 2 || rankDelta != 1) && (rankDelta != 2 || fileDelta != 1)) {
		cout << "invalid Knight move" << endl;
		return false;
	}

	else if (Board::board[destFile][destRank].isOccupied == true) {
		cout << "collision" << endl;
		return false;
	}

	else {
		return true;
	}
}

bool Knight::ValidateKnightAttack(int fileDelta, int rankDelta) {
	int destFile = FileIndex + fileDelta;
	int destRank = RankIndex + rankDelta;
	fileDelta = fileDelta * 1;
	rankDelta = rankDelta * 1;

	if (FileIndex + fileDelta > 7 || RankIndex + rankDelta > 7 || RankIndex + rankDelta < 0 || FileIndex + fileDelta < 0)
	{
		cout << "off the board" << endl;
		return false;
	}

	else if ((fileDelta != 2 || rankDelta != 1) || (rankDelta != 2 || fileDelta != 1)) {
		cout << "invalid Knight move" << endl;
		return false;
	}

	else if (Board::board[destFile][destRank].isOccupied == false) {
		cout << "square not occupied" << endl;
		return true;
	}

	else {
		return true;
	}

}

void Knight::KnightMove(int DestFile, int DestRank) {
	int fileDelta = DestFile - FileIndex;
	int rankDelta = DestRank - RankIndex;


	if (ValidateKnightMove(fileDelta, rankDelta) == true) {
		Move(DestFile, DestRank);
	}
}

void Knight::KnightAttack(int DestFile, int DestRank) {
	int fileDelta = DestFile - FileIndex;
	int rankDelta = DestRank - RankIndex;


	if (ValidateKnightAttack(fileDelta, rankDelta) == true) {
		Move(DestFile, DestRank);
	}
}

Knight::Knight(int file, int rank, string colour)
	: Piece(file, rank, colour)
{
	this->Symbol = "N";
}