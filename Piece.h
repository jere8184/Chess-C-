#pragma once


#include "Board.h"
#include "Square.h"
#include<string>
#include<tuple>

using namespace std;

class Piece {


public:

	int RankIndex;

	int FileIndex;

	void Captured();

	bool IsCaptured = false;

	bool ValidateDiagAttack(int fileDelta, int rankDelta);

	bool ValidateStraightAttack(int fileDelta, int rankDelta);

	string Coordinate;

	string Symbol = "U";

	string Team;

	Square* Square;

	Piece(int fileIndex, int rankIndex);

	void Move(int File, int Rank);

	void Attack(int File, int Rank);

	static string To_Coordinate(int fileIndex, int rankIndex);

	static tuple<int, int> To_indexs(string coordinate);

	void Move(string coordinate);

	bool ValidateStraightMove(int fileDelta, int rankDelta);

	bool ValidateDiagMove(int fileDelta, int rankDelta);

};
