#include "Piece.h"
#include "Queen.h"

using namespace std;


	Piece::Piece(int fileIndex, int rankIndex, string colour)
		: FileIndex(fileIndex), RankIndex(rankIndex), Colour(colour), Coordinate(To_Coordinate(FileIndex, RankIndex)),Square(&Board::board[FileIndex][RankIndex])
	{
		this->Square -> isOccupied = true;
		this->Square -> Occupiere = this;
	}

	string Piece::To_Coordinate(int fileIndex, int rankIndex) {

		string coordinate;
		switch (fileIndex) {
		case 0:
			coordinate += "a";
			break;
		case 1:
			coordinate += "b";
			break;
		case 2:
			coordinate += "c";
			break;
		case 3:
			coordinate += "d";
			break;
		case 4:
			coordinate += "e";
			break;
		case 5:
			coordinate += "f";
			break;
		case 6:
			coordinate += "g";
			break;
		case 7:
			coordinate += "h";
			break;
		}
		return coordinate += to_string(rankIndex + 1); //chess coordinate = index + 1 as chess coordinate starts at 1 (i.e. a1)
	}

	tuple<int, int> Piece::To_indexs(string coordinate) {

		char fileChar = coordinate[0];
		int file = 0;
		char rankChar = coordinate[1];
		int rank = rankChar - '1'; //index = -1 chess coordinate as index begins at 0
		switch (fileChar) {
		case 'a':
			file = 0;
			break;
		case 'b':
			file = 1;
			break;
		case 'c':
			file += 2;
			break;
		case 'd':
			file += 3;
			break;
		case 'e':
			file += 4;
			break;
		case 'f':
			file += 5;
			break;
		case 'g':
			file += 6;
			break;
		case 'h':
			file += 7;
			break;
		}
		return make_tuple(file, rank);
	}

	void Piece::Move(int file, int rank) {
		this->Square->isOccupied = false;
		this->Square->Occupiere = nullptr;
		this->RankIndex = rank;
		this->FileIndex = file;
		this->Coordinate = To_Coordinate(file, rank);
		this->Square = &Board::board[file][rank];
		this->Square->isOccupied = true;
		this->Square->Occupiere = this;
		this->Moved = true;
	}


	void Piece::Move(string coordinate) {
		this->Square -> isOccupied = false;
		this->Square -> Occupiere = nullptr;
		int file = get<0>(To_indexs(coordinate));
		int rank = get<1>(To_indexs(coordinate));
		this->FileIndex = file;
		this->RankIndex = rank;
		this->Coordinate = coordinate;
		this->Square = &Board::board[file][rank];
		this->Square->isOccupied = true;
		this->Square->Occupiere = this;
		this->Moved = true;
	}

	bool Piece::ValidateMove(int destFile, int destRank) {

		int fileDelta = destFile - FileIndex;
		int rankDelta = destRank - RankIndex;

		if (this->Type == "Rook" && (fileDelta != 0 && rankDelta != 0))
		{
			cout << "invalid rook move";
			return false;
		}

		else if (this->Type == "Bishop" && (abs(fileDelta) != abs(rankDelta)))
		{
			cout << "invalid bishop move";
			return false;
		}

		else if (this->Type == "King" && (abs(fileDelta) > 1  || abs(rankDelta) > 1))
		{
			cout << "invalid king move";
			return false;
		}

		if (FileIndex + fileDelta > 7 || RankIndex + rankDelta > 7 || RankIndex + rankDelta < 0 || FileIndex + fileDelta < 0)
		{
			cout << "off the board" << endl;
			return false;
		}

		else if (fileDelta != 0 && rankDelta != 0) 
		{
			cout << "non linear move" << endl;
			return false;
		}


		else if (Search(destFile, destRank) == true)
		{
			return true;
		}

		else
		{
			return false;
		}


	}

	void Piece::Captured() {
		
		this->Square->Occupiere = nullptr;
		this->Square->isOccupied = false;
		this->IsCaptured = true;
	}


	void Piece::Attack(int file, int rank) {

		this->Square->isOccupied = false;
		this->Square->Occupiere = nullptr;
		this->RankIndex = rank;
		this->FileIndex = file;
		this->Coordinate = To_Coordinate(file, rank);
		Board::board[file][rank].Occupiere->Captured();
		this->Square = &Board::board[file][rank];
		this->Square->isOccupied = true;
		this->Square->Occupiere = this;
		this->Moved = true;
	}

	void Piece::TryMove(int destFile, int destRank) {
		if (ValidateMove(destFile, destRank) == true)
		{
			Board::board[destFile][destRank].isOccupied ? Attack(destFile, destRank) : Move(destFile, destRank);
		}
	}


	//searches squares INBETWEEN starting postion and destination postion, returns true if all squares unoccupied, or false if one of the squares is occupied
	bool Piece::Search(int destFile, int destRank) {

		int fileDelta = destFile - this->FileIndex;
		int rankDelta = destRank - this->RankIndex;
		int fileDirection; //will either be +1 or -1
		int rankDirection; //will either be +1 or -1
		bool moveFile = false;
		bool moveRank = false;

		if (fileDelta != 0) {
			fileDirection = fileDelta > 0 ? +1 : -1;
			moveFile = true;
		}

		if (rankDelta != 0) {
			rankDirection = rankDelta > 0 ? +1 : -1;
			moveRank = true;
		}


		if (moveFile == true && moveRank == false)
		{
			for (int i = FileIndex + fileDirection; i * fileDirection < destFile * fileDirection; i += fileDirection) {
				if (Board::board[i][RankIndex].isOccupied == true) {
					return false;
				}
			}
			return true;
		}

		if (moveFile == false && moveRank == true)
		{
			for (int i = RankIndex + rankDirection; i * rankDirection < destRank * rankDirection; i += rankDirection) {
				if (Board::board[FileIndex][i].isOccupied == true) {
					return false;
				}
			}
			return true;
		}

		if (moveFile == true && moveRank == true)
		{
			int j = RankIndex + rankDirection;

			for (int i = FileIndex + fileDirection; i * fileDirection < destFile * fileDirection; i += fileDirection) {
				if (Board::board[i][j].isOccupied == true) {
					return false;
				}
				j += rankDirection;
			}
			return true;
		}
	}




