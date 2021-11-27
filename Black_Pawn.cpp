#include "Black_Pawn.h"

Black_Pawn::Black_Pawn(int file, int rank)
	: Piece(file, rank, "Black")
{
	this->Symbol = "P";
	this->Type = "Black_Pawn";
}

bool Black_Pawn::PawnMove(int destFile, int destRank) {

	if (ValidateStraightMove(destFile, destRank) == true && ValidatePawnMove(destFile, destRank) == true) { 
		Move(destFile, destRank);
		return true;
	}
	return false;
}

bool Black_Pawn::PawnAttack(int destFile, int destRank) {

	if (ValidateDiagAttack(destFile, destRank) == true && ValidatePawnAttack(destFile, destRank) == true) {
		Attack(destFile, destRank);
		return true;
	}
	return false;
}

bool Black_Pawn::ValidatePawnMove(int destFile, int destRank) {
	int fileDelta = destFile - FileIndex;
	int rankDelta = destRank - RankIndex;
	if (rankDelta == -2 && fileDelta == 0 && Moved == false) {
		return true;
	}
	else if (rankDelta == -1 && fileDelta == 0) {

		return true;
	}
	cout << "invalid pawn move";
	return false;
}

bool Black_Pawn::ValidatePawnAttack(int destFile, int destRank) {
	int fileDelta = destFile - FileIndex;
	int rankDelta = destRank - RankIndex;
	if (rankDelta == -1 && fileDelta == -1 && Moved == false) {
		return true;
	}
	else if (rankDelta == -1 && fileDelta == +1) {

		return true;
	}
	cout << "invalid pawn move";
	return false;
}

void Black_Pawn::TryMove(int destFile, int destRank) {
	if (PawnMove(destFile, destRank)) {
		return;
	}
	else if(PawnAttack(destFile, destRank)) {
		return;
	}
		
}