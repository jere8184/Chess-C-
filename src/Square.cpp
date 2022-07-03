#include "Square.h"
#include "Board.h"

Square::Square(int file, int rank)
{
	SetRank(rank);
	SetFile(file);
	SetCooridnate(Board::To_Coordinate(file, rank));
	SetColour();
}

void Square::SetColour()
{
	if((GetRank() + GetFile()) % 2 == 0)
	{
		Colour = sf::Color(sf::Uint8(0), sf::Uint8(0), sf::Uint8(255));
	}
	else
	{
		Colour = sf::Color(sf::Uint8(255), sf::Uint8(255), sf::Uint8(255));
	}
}

void Square::SetSprite(float size)
{
	sf::RectangleShape sprite(sf::Vector2f(size, size));
	Sprite = sprite;
	float x = GetFile() * size;
	float y = size * 7 - (GetRank() * size);
	Sprite.setPosition(x, y);
	Sprite.setFillColor(GetColour());
}
