#include "Bishop.h"


void Bishop::BishopDiagMove(int DestFile, int DestRank) {
	int fileDelta = DestFile - FileIndex;
	int rankDelta = DestRank - RankIndex;

	if (ValidateDiagMove(DestFile, DestRank) == true) {
		Move(DestFile, DestRank);
	}
}

void Bishop::BishopDiagAttack(int DestFile, int DestRank) {
	if (ValidateDiagAttack(DestFile, DestRank) == true) {
		Attack(DestFile, DestRank);
	}
}

Bishop::Bishop(int file, int rank, string colour)
	: Piece(file, rank, colour)
{
	this->Symbol = "B";
}