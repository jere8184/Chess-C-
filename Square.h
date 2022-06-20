#pragma once


class Piece;

#include<string>


using namespace std;

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


private:
	string Coordinate;
	int FileIndex;
	int RankIndex;
	Piece* Occupiere;
	bool Occupied = false;
};