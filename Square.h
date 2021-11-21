#pragma once


class Piece;

#include<string>


using namespace std;

class Square{
public:
	string coordinate;
	int FileIndex;
	int RankIndex;
	Piece* Occupiere;
	bool isOccupied = false;
};