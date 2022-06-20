#pragma once

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
	bool IsCaptured = false;
	string Coordinate;
	string Type = "Undefined";
	Square* Position;
		




protected:

	bool Moved = false;

	void SetRank(int rank) { RankIndex = rank; }
	void SetFile(int file) { FileIndex = file; }

	int GetRank() { return RankIndex; }
	int GetFile() { return FileIndex; }

	int GetFileDelta(int destFile) {return destFile - FileIndex;}
	int GetRankDelta(int destRank) {return destRank - RankIndex;}

	void SetSymbol(string symbol) { Symbol = symbol; }


	Square* GetPosition() { return Position; }
	void SetPosition(Square* iPositon);

	string GetColour() { return Colour;}

	void SetType(string type) { Type = type; }

	void Captured();

	Piece(int fileIndex, int rankIndex, string colour);

	void Move(int file, int rank);

	void Attack(int file, int rank);

	static string To_Coordinate(int fileIndex, int rankIndex);

	static tuple<int, int> To_indexs(string coordinate);

	void Move(string coordinate);

	bool Search(int destFile, int destRank);

	virtual bool ValidateMove(int destFile, int destRank) = 0;

	bool IsLinearMove(int fileDelta, int rankDelta);

	bool IsStraightMove(int fileDelta, int rankDelta);

	bool IsDiaganolMove(int fileDelta, int rankDelta);

	bool StandardChecks(int fileDelta, int rankDelta);

public:
	string GetSymbol() { return Symbol; }
	string GetType() { return Type; }
	void TryMove(int file, int rank);
};
