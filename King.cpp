#include "King.h"

King::King(int file, int rank, string colour)
	: Piece(file, rank, colour)
{
	this->Symbol = "K";
	this->Type = "King";
}
