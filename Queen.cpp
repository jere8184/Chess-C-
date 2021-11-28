#include "Queen.h"


Queen::Queen(int file, int rank, string colour)
	: Piece(file, rank, colour)
{
	this->Symbol = "Q";
	this->Type = "Queen";
}
