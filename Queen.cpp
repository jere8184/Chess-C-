#include "Queen.h"

void Queen::QueenStraightMove(int DestFile, int DestRank) {
	int fileDelta = DestFile - FileIndex;
	int rankDelta = DestRank - RankIndex;
	
	if (ValidateStraightMove(DestFile, DestRank) == true) {
		Move(DestFile, DestRank);
	}
}

void Queen::QueenDiagMove(int DestFile, int DestRank) {
	int fileDelta = DestFile - FileIndex;
	int rankDelta = DestRank - RankIndex;

	if (ValidateDiagMove(DestFile, DestRank) == true) {
		Move(DestFile, DestRank);
	}
}

void Queen::QueenDiagAttack(int DestFile, int DestRank) {
	if (ValidateDiagAttack(DestFile, DestRank) == true) {
		Attack(DestFile, DestRank);
	}
}

void Queen::QueenStraightAttack(int DestFile, int DestRank) {
	if (ValidateStraightAttack(DestFile, DestRank) == true) {
		Attack(DestFile, DestRank);
	}
}


Queen::Queen(int file, int rank, string colour)
	: Piece(file, rank, colour)
{
	this->Symbol = "Q";
}
