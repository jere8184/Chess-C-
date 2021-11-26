#include "Rook.h"


void Rook::TryMove(int DestFile, int DestRank) {
	RookStraightMove(DestFile, DestRank);
	RookStraightAttack(DestFile, DestRank);
}

void Rook::RookStraightMove(int DestFile, int DestRank) {
	if (ValidateStraightMove(DestFile, DestRank) == true) {
		Move(DestFile, DestRank);
	}
}



void Rook::RookStraightAttack(int DestFile, int DestRank) {
	if (ValidateStraightAttack(DestFile, DestRank) == true) {
		Attack(DestFile, DestRank);
	}
}



Rook::Rook(int file, int rank, string colour)
	: Piece(file, rank, colour)
{
	this->Symbol = "R";
	this->Type = "Rook";
}
