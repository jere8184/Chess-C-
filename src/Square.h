#pragma once

#include <SFML/Graphics.hpp>
#include<string>

using namespace std;
class Piece;
class Board;

class Square{
public:
	bool IsOccupied() {return Occupied;}
	void SetOccupation(bool isOccupied) { Occupied = isOccupied; }

	string GetCoordinate() {return Coordinate;}
	void SetCooridnate(string coordinate) { Coordinate = coordinate; }

	Piece* GetOccupier() { return Occupiere;}
	void SetOccupier(Piece* piece) { Occupiere = piece; }
	
	int GetRank() { return RankIndex; }
	void SetRank(int rank) { RankIndex = rank; }

	int GetFile() { return FileIndex; }
	void SetFile(int file) { FileIndex = file; }

	sf::Color GetColour() { return Colour; }
	void SetColour();

	sf::RectangleShape* GetSprite() { return &Sprite; }
	void SetSprite(float size);

	Square(int file, int rank);


private:
	string Coordinate;
	int FileIndex;
	int RankIndex;
	Piece* Occupiere;
	bool Occupied = false;
	sf::Color Colour;
	sf::RectangleShape Sprite;
};