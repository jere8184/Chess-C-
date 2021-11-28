#include "Bishop.h"

Bishop::Bishop(int file, int rank, string colour)
	: Piece(file, rank, colour)
{
	this->Symbol = "B";
	this->Type = "Bishop";
}