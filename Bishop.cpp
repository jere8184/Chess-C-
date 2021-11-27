#include "Bishop.h"


void Bishop::BishopDiagMove(int DestFile, int DestRank) {
	if (ValidateDiagMove(DestFile, DestRank) == true) {
		Move(DestFile, DestRank);
	}
}

void Bishop::BishopDiagAttack(int DestFile, int DestRank) {
	if (ValidateDiagAttack(DestFile, DestRank) == true) {
		Attack(DestFile, DestRank);
	}
}

void Bishop::TryMove(int DestFile, int DestRank) {
	BishopDiagMove(DestFile, DestRank);
	BishopDiagAttack(DestFile, DestRank);
}

Bishop::Bishop(int file, int rank, string colour)
	: Piece(file, rank, colour)
{
	this->Symbol = "B";
	this->Type = "Bishop";
}