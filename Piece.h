#pragma once

#include<tuple>
#include "Board.h"
#include "Square.h"
#include<string>

using namespace std;

class Piece {

private:
	int RankIndex;
	int FileIndex;
	string Colour;
	string Symbol = "U";

public:

	bool Moved = false;

	void SetRank(int rank) { RankIndex = rank; }
	void SetFile(int file) { FileIndex = file; }

	int GetRank() { return RankIndex; }
	int GetFile() { return FileIndex; }

	int GetFileDelta(int destFile) {return FileIndex - destFile;}
	int GetRankDelta(int destRank) {return RankIndex - destRank;}

	void SetSymbol(string symbol) { Symbol = symbol; }
	string GetSymbol() { return Symbol; }

	string GetColour() { return Colour;}




	void Captured();

	bool IsCaptured = false;

	string Coordinate;

	string Type = "U";

	Square* Square;

	Piece(int fileIndex, int rankIndex, string colour);

	void Move(int file, int rank);

	void Attack(int file, int rank);

	static string To_Coordinate(int fileIndex, int rankIndex);

	static tuple<int, int> To_indexs(string coordinate);

	void Move(string coordinate);

	void TryMove(int file, int rank);

	bool Search(int destFile, int destRank);

	virtual bool ValidateMove(int destFile, int destRank) = 0;

	bool IsLinearMove(int fileDelta, int rankDelta);

	bool IsStraightMove(int fileDelta, int rankDelta);

	bool IsDiaganolMove(int fileDelta, int rankDelta);

	bool StandardChecks(int fileDelta, int rankDelta);
};
