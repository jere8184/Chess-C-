#include "King.h"


bool King::ValidateKingMove(int fileDelta, int rankDelta) {
	fileDelta = fileDelta * 1;
	rankDelta = rankDelta * 1;
	if ((fileDelta != 1 && fileDelta != 0) || (rankDelta != 1 && rankDelta != 0)) {
		cout << "king can only move one square at a time" << endl;
		return false;
	}
	else {
		return true;
	}
}

void King::KingStraightMove(int DestFile, int DestRank) {
	int fileDelta = DestFile - FileIndex;
	int rankDelta = DestRank - RankIndex;


	if (ValidateStraightMove(DestFile, DestRank) == true && ValidateKingMove(fileDelta, rankDelta) == true) {
		Move(DestFile, DestRank);
	}
}

void King::KingDiagMove(int DestFile, int DestRank) {
	int fileDelta = DestFile - FileIndex;
	int rankDelta = DestRank - RankIndex;

	if (ValidateDiagMove(DestFile, DestRank) == true && ValidateKingMove(fileDelta, rankDelta) == true) {
		Move(DestFile, DestRank);
	}
}

void King::KingDiagAttack(int DestFile, int DestRank) {
	int fileDelta = DestFile - FileIndex;
	int rankDelta = DestRank - RankIndex;

	if (ValidateDiagAttack(DestFile, DestRank) == true && ValidateKingMove(fileDelta, rankDelta) == true) {
		Attack(DestFile, DestRank);
	}
}

void King::KingStraightAttack(int DestFile, int DestRank) {
	int fileDelta = DestFile - FileIndex;
	int rankDelta = DestRank - RankIndex;

	if (ValidateStraightAttack(DestFile, DestRank) == true && ValidateKingMove(fileDelta, rankDelta) == true) {
		Attack(DestFile, DestRank);
	}
}


King::King(int file, int rank, string colour)
	: Piece(file, rank, colour)
{
	this->Symbol = "K";
}
