#include "White_Pawn.h"


White_Pawn::White_Pawn(int file, int rank)
	: Piece(file, rank, "White")
{
	this->Symbol = "p";
}

void White_Pawn::Move1() {

	if (ValidateStraightMove(0, 1) == true) {
		Move(FileIndex, RankIndex + 1);
	}
}

void White_Pawn::Move2() {

	if (ValidateStraightMove(0, 2) == true) {
		Move(FileIndex, RankIndex + 2);
	}
}

void White_Pawn::AttackRight() {
	
	if (ValidateDiagAttack(1,1) == true) {
		Attack(FileIndex + 1, RankIndex + 1);
	}
}

void White_Pawn::AttackLeft() {

	if (ValidateDiagAttack(-1, 1) == true) {
		Attack(FileIndex - 1, RankIndex + 1);
	}
}