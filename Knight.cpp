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

	else if (Board::board[destFile][destRank].isOccupied == true) {
		cout << "collision" << endl;
		return false;
	}

	else {
		return true;
	}
}

bool Knight::ValidateKnightAttack(int DestFile, int DestRank) {
	int fileDelta = DestFile - FileIndex;
	int rankDelta = DestRank - RankIndex;


	if (FileIndex + fileDelta > 7 || RankIndex + rankDelta > 7 || RankIndex + rankDelta < 0 || FileIndex + fileDelta < 0)
	{
		cout << "off the board" << endl;
		return false;
	}


	else if ((abs(fileDelta) != 2 || abs(rankDelta) != 1) && (abs(rankDelta) != 2 || abs(fileDelta) != 1)) {
		cout << "invalid Knight move" << endl;
		return false;
	}

	else if (Board::board[DestFile][DestRank].isOccupied == false) {
		cout << "square not occupied" << endl;
		return true;
	}

	else {
		return true;
	}

}

void Knight::KnightMove(int DestFile, int DestRank) {
	if (ValidateKnightMove(DestFile, DestRank) == true) {
		Move(DestFile, DestRank);
	}
}

void Knight::KnightAttack(int DestFile, int DestRank) {
	if (ValidateKnightAttack(DestFile, DestRank) == true) {
		Move(DestFile, DestRank);
	}
}


void Knight::TryMove(int DestFile, int DestRank) {
	KnightAttack(DestFile, DestRank);
	KnightMove(DestFile, DestRank);
}

Knight::Knight(int file, int rank, string colour)
	: Piece(file, rank, colour)
{
	this->Symbol = "N";
	this->Type = "Knight";
}