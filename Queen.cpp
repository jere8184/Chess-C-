#include "Queen.h"

void Queen::QueenStraightMove(int destFile, int destRank) {	
	if (ValidateStraightMove(destFile, destRank) == true) {
		Move(destFile, destRank);
	}
}

void Queen::QueenDiagMove(int destFile, int destRank) {
	if (ValidateDiagMove(destFile, destRank) == true) {
		Move(destFile, destRank);
	}
}

void Queen::QueenDiagAttack(int destFile, int destRank) {
	if (ValidateDiagAttack(destFile, destRank) == true) {
		Attack(destFile, destRank);
	}
}

void Queen::QueenStraightAttack(int destFile, int destRank) {
	if (ValidateStraightAttack(destFile, destRank) == true) {
		Attack(destFile, destRank);
	}
}

void Queen::TryMove(int destFile, int destRank) {
	QueenStraightAttack(destFile, destRank);
	QueenDiagAttack(destFile, destRank);
	QueenDiagMove(destFile, destRank);
	QueenStraightMove(destFile, destRank);
}


Queen::Queen(int file, int rank, string colour)
	: Piece(file, rank, colour)
{
	this->Symbol = "Q";
	this->Type = "Queen";
}
