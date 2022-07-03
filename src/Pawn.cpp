#include "Pawn.h"

Pawn::Pawn(int file, int rank, string colour)
	: Piece(file, rank, colour)
{
	SetSymbol("p");
	SetType("Pawn");
	IsWhite() ? SetTexture("white_pawn.png") : SetTexture("black_pawn.png");
}

bool Pawn::ValidateMove(int destFile, int destRank) 
{
	int fileDelta = GetFileDelta(destFile);
	int rankDelta = GetRankDelta(destRank);

	int direction = GetColour() == "White" ? 1 : -1;
	bool isOccupied = Board::GetSquare(destFile, destRank)->IsOccupied();
	if(isOccupied)
	{
		return ValidateAttack(destFile, destRank);
	}
	else if (rankDelta == direction * 2 && fileDelta == 0 && !Moved && !isOccupied)
	{
		return true;
	}
	else if (rankDelta == direction && fileDelta == 0 && !isOccupied)
	{
		return true;
	}
	cout << "invalid pawn move" << endl;
	return false;
}

//Pawns captuer is a speical move
bool Pawn::ValidateAttack(int destFile, int destRank) {
	int fileDelta = GetFileDelta(destFile);
	int rankDelta = GetRankDelta(destRank);
	int direction = IsWhite() ? 1 : -1;
	if (rankDelta == direction && abs(fileDelta) == 1 && Board::GetSquare(destFile, destRank)->IsOccupied())
	{
		return true;
	}
	cout << "invalid pawn attack";
	return false;
}