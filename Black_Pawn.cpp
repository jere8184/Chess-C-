#include "Black_Pawn.h"

Black_Pawn::Black_Pawn(int file, int rank)
	: Piece(file, rank)
{
	this->Symbol = "P";
}

void Black_Pawn::Move1() {

	if (ValidateMove(0, -1) == true) {
		Move(FileIndex, RankIndex - 1);
	}
}

void Black_Pawn::Move2() {

	if (ValidateMove(0, -2) == true) {
		Move(FileIndex, RankIndex -2);
	}
}

void Black_Pawn::AttackRight() {

	if (ValidateAttack(1, -1) == true) {
		Attack(FileIndex + 1, RankIndex - 1);
	}
}

void Black_Pawn::AttackLeft() {

	if (ValidateAttack(-1, -1) == true) {
		Attack(FileIndex - 1, RankIndex - 1);
	}
}