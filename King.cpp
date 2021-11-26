#include "King.h"


bool King::ValidateKingMove(int destFile, int destRank) {
	int fileDelta = destFile - FileIndex;
	int rankDelta = destRank - RankIndex;
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
	if (ValidateStraightMove(DestFile, DestRank) == true && ValidateKingMove(DestFile, DestRank) == true) {
		Move(DestFile, DestRank);
	}
}

void King::KingDiagMove(int DestFile, int DestRank) {

	if (ValidateDiagMove(DestFile, DestRank) == true && ValidateKingMove(DestFile, DestRank) == true) {
		Move(DestFile, DestRank);
	}
}

void King::KingDiagAttack(int DestFile, int DestRank) {
	if (ValidateDiagAttack(DestFile, DestRank) == true && ValidateKingMove(DestFile, DestRank) == true) {
		Attack(DestFile, DestRank);
	}
}

void King::KingStraightAttack(int DestFile, int DestRank) {
	if (ValidateStraightAttack(DestFile, DestRank) == true && ValidateKingMove(DestFile, DestRank) == true) {
		Attack(DestFile, DestRank);
	}
}

void King::TryMove(int DestFile, int DestRank) {
	KingStraightAttack(DestFile,  DestRank);
	KingDiagAttack(DestFile, DestRank);
	KingStraightMove(DestFile, DestRank);
	KingDiagMove(DestFile, DestRank);
}


King::King(int file, int rank, string colour)
	: Piece(file, rank, colour)
{
	this->Symbol = "K";
	this->Type = "King";
}
