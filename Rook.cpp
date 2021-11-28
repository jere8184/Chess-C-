#include "Rook.h"


Rook::Rook(int file, int rank, string colour)
	: Piece(file, rank, colour)
{
	this->Symbol = "R";
	this->Type = "Rook";
}
