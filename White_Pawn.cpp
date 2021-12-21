#include "White_Pawn.h"


White_Pawn::White_Pawn(int file, int rank)
	: Piece(file, rank, "White")
{
	this->Symbol = "p";
	this->Type = "White_Pawn";
}

void White_Pawn::PawnMove(int destFile, int destRank) {

	if (ValidateMove(destFile, destRank) == true && ValidatePawnMove(destFile, destRank) == true) {
		Move(destFile, destRank);
	}
}

void White_Pawn::PawnAttack(int destFile, int destRank) {

	if (ValidateMove(destFile, destRank) == true && ValidatePawnAttack(destFile, destRank) == true) {
		Attack(destFile, destRank);
	}
}

bool White_Pawn::ValidatePawnMove(int destFile, int destRank) {
	int fileDelta = destFile - FileIndex;
	int rankDelta = destRank - RankIndex;
	if (rankDelta == 2 && fileDelta == 0 && Moved == false) {
		return true;
	}
	else if (rankDelta == 1 && fileDelta == 0) {

		return true;
	}
	cout << "invalid pawn move" << endl;
	return false;
}

bool White_Pawn::ValidatePawnAttack(int destFile, int destRank) {
	int fileDelta = destFile - FileIndex;
	int rankDelta = destRank - RankIndex;
	if (rankDelta == 1 && fileDelta == -1 && Moved == false) {
		return true;
	}
	else if (rankDelta == 1 && fileDelta == +1) {

		return true;
	}
	cout << "invalid pawn move";
	return false;
}

void White_Pawn::TryMove(int destFile, int destRank) {
	PawnMove(destFile, destRank);
	PawnAttack(destFile, destRank);
}