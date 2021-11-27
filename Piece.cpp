#include "Piece.h"
#include "Queen.h"

using namespace std;


	Piece::Piece(int fileIndex, int rankIndex, string colour)
		: FileIndex(fileIndex), RankIndex(rankIndex), Colour(colour), Coordinate(To_Coordinate(FileIndex, RankIndex)),Square(&Board::board[FileIndex][RankIndex])
	{
		//this->RankIndex = rankIndex;
		//this->FileIndex = fileIndex;
		//this->Coordinate = To_Coordinate(FileIndex, RankIndex);
		//this->Square = &Board::board[FileIndex][RankIndex];
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

	bool Piece::ValidateStraightMove(int destFile, int destRank) {

		int fileDelta = destFile - FileIndex;
		int rankDelta = destRank - RankIndex;


		auto CheckUp = [this, rankDelta]() {
			int destRank = RankIndex + rankDelta;

			for (int rank = RankIndex + 1; rank < destRank + 1; rank++) {
				if (Board::board[FileIndex][rank].isOccupied == true) {
					return false;
				}
			}
			return true;
		};

		auto CheckDown = [this, rankDelta]() {
			int destRank = RankIndex + rankDelta;

			for (int rank = RankIndex - 1; rank > destRank - 1; rank--) {
				if (Board::board[FileIndex][rank].isOccupied == true) {
					return false;
				}
			}
			return true;
		};

		auto CheckLeft = [this, fileDelta]() {
			int destFile = FileIndex + fileDelta;

			for (int file = FileIndex - 1; file > destFile - 1; file--) {
				if (Board::board[file][RankIndex].isOccupied == true) {
					return false;
				}
			}
			return true;
		};

		auto CheckRight = [this, fileDelta]() {
			int destFile = FileIndex + fileDelta;

			for (int file = FileIndex + 1; file < destFile + 1; file++) {
				if (Board::board[file][RankIndex].isOccupied == true) {
					return false;
				}
			}
			return true;
		};


		if (FileIndex + fileDelta > 7 || RankIndex + rankDelta > 7 || RankIndex + rankDelta < 0 || FileIndex + fileDelta < 0)
		{
			cout << "off the board" << endl;
			return false;
		}

		else if (fileDelta != 0 && rankDelta != 0) {
			cout << "non linear move" << endl;
			return false;
		}

		else if (rankDelta > 0 && CheckUp() == true) {
			return true;
		}

		else if (CheckDown() == true && rankDelta < 0) {
			return true;
		}

		else if (CheckRight() == true && fileDelta > 0) {
			return true;
		}

		else if (CheckLeft() == true && fileDelta < 0) {
			return true;
		}

		else
		{
			cout << "collision" << endl;
			return false;
		}


	}

	bool Piece::ValidateDiagMove(int destFile, int destRank) {

		int fileDelta = destFile - FileIndex;
		int rankDelta = destRank - RankIndex;

		auto CheckUpRight = [this, fileDelta]() {
			int destFile = FileIndex + fileDelta;
			int rank = RankIndex + 1;

			for (int file = FileIndex + 1; file < destFile + 1; file++) {

				if (Board::board[file][rank].isOccupied == true) {
					return false;
				}
				rank++;
			}
			return true;
		};

		auto CheckUpLeft = [this, fileDelta]() {
			int destFile = FileIndex + fileDelta;
			int rank = RankIndex + 1;

			for (int file = FileIndex - 1; file > destFile - 1; file--) {

				if (Board::board[file][rank].isOccupied == true) {
					return false;
				}
				rank++;
			}
			return true;
		};

		auto CheckDownRight = [this, fileDelta]() {
			int destFile = FileIndex + fileDelta;
			int rank = RankIndex + 1;

			for (int file = FileIndex + 1; file < destFile + 1; file++) {

				if (Board::board[file][rank].isOccupied == true) {
					return false;
				}
				rank--;
			}
			return true;
		};

		auto CheckDownLeft = [this, fileDelta]() {
			int destFile = FileIndex + fileDelta;
			int rank = RankIndex + 1;

			for (int file = FileIndex - 1; file > destFile - 1; file--) {

				if (Board::board[file][rank].isOccupied == true) {
					return false;
				}
				rank--;
			}
			return true;
		};

		if (FileIndex + fileDelta > 7 || RankIndex + rankDelta > 7 || RankIndex + rankDelta < 0 || FileIndex + fileDelta < 0)
		{
			cout << "off the board" << endl;
			return false;
		}

		else if (fileDelta*1 != rankDelta*1) {
			cout << "non Diag move" << endl;
			return false;
		}

		else if (CheckUpRight() == true && fileDelta > 0 && rankDelta > 0) {
			return true;
		}

		else if (CheckUpLeft() == true && fileDelta < 0 && rankDelta > 0) {
			return true;
		}

		else if (CheckDownRight() == true && fileDelta > 0 && rankDelta < 0) {
			return true;
		}

		else if (CheckDownLeft() == true && fileDelta < 0 && rankDelta < 0) {
			return true;
		}

		else
		{
			cout << "collision" << endl;
			return false;
		}
	}

	bool Piece::ValidateDiagAttack(int destFile, int destRank) {
		
		int fileDelta = destFile - FileIndex;
		int rankDelta = destRank - RankIndex;

		auto CheckUpRight = [this, fileDelta]() {
			int destFile = FileIndex + fileDelta;
			int rank = RankIndex + 1;

			for (int file = FileIndex + 1; file < destFile; file++) {

				if (Board::board[file][rank].isOccupied == true) {
					return false;
				}
				rank++;
			}
			return true;
		};

		auto CheckUpLeft = [this, fileDelta]() {
			int destFile = FileIndex + fileDelta;
			int rank = RankIndex + 1;

			for (int file = FileIndex - 1; file > destFile; file--) {

				if (Board::board[file][rank].isOccupied == true) {
					return false;
				}
				rank++;
			}
			return true;
		};

		auto CheckDownRight = [this, fileDelta]() {
			int destFile = FileIndex + fileDelta;
			int rank = RankIndex + 1;

			for (int file = FileIndex + 1; file < destFile; file++) {

				if (Board::board[file][rank].isOccupied == true) {
					return false;
				}
				rank--;
			}
			return true;
		};

		auto CheckDownLeft = [this, fileDelta]() {
			int destFile = FileIndex + fileDelta;
			int rank = RankIndex + 1;

			for (int file = FileIndex - 1; file > destFile; file--) {

				if (Board::board[file][rank].isOccupied == true) {
					return false;
				}
				rank--;
			}
			return true;
		};

		if (FileIndex + fileDelta > 7 || RankIndex + rankDelta > 7 || RankIndex + rankDelta < 0 || FileIndex + fileDelta < 0)
		{
			cout << "off the board" << endl;
			return false;
		}

		else if (abs(fileDelta) * 1 != abs(rankDelta) * 1) {
			cout << "non Diag attack" << endl;
			return false;
		}

		if (Board::board[destFile][destRank].isOccupied == false) 
		{
			cout << "square not occupied" << endl;
			return false;
		}

		else if (Board::board[destFile][destRank].Occupiere->Colour == this->Colour)
		{
			cout << "cannot capture piece of same colour" << endl;
			return false;
		}

		else if (CheckUpRight() == true && fileDelta > 0 && rankDelta > 0) {
			return true;
		}

		else if (CheckUpLeft() == true && fileDelta < 0 && rankDelta > 0) {
			return true;
		}

		else if (CheckDownRight() == true && fileDelta > 0 && rankDelta < 0) {
			return true;
		}

		else if (CheckDownLeft() == true && fileDelta < 0 && rankDelta < 0) {
			return true;
		}

		else
		{
			cout << "collision" << endl;
			return false;
		}

		return true;
	}

	bool Piece::ValidateStraightAttack(int destFile, int destRank) {

		int fileDelta = destFile - FileIndex;
		int rankDelta = destRank - RankIndex;

		auto CheckUp = [this, rankDelta]() {
			int destRank = RankIndex + rankDelta;

			for (int rank = RankIndex + 1; rank < destRank; rank++) {
				if (Board::board[FileIndex][rank].isOccupied == true) {
					return false;
				}
			}
			return true;
		};

		auto CheckDown = [this, rankDelta]() {
			int destRank = RankIndex + rankDelta;

			for (int rank = RankIndex - 1; rank > destRank; rank--) {
				if (Board::board[FileIndex][rank].isOccupied == true) {
					return false;
				}
			}
			return true;
		};

		auto CheckLeft = [this, fileDelta]() {
			int destFile = FileIndex + fileDelta;

			for (int file = FileIndex - 1; file > destFile; file--) {
				if (Board::board[file][RankIndex].isOccupied == true) {
					return false;
				}
			}
			return true;
		};

		auto CheckRight = [this, fileDelta]() {
			int destFile = FileIndex + fileDelta;

			for (int file = FileIndex + 1; file < destFile; file++) {
				if (Board::board[file][RankIndex].isOccupied == true) {
					return false;
				}
			}
			return true;
		};


		if (FileIndex + fileDelta > 7 || RankIndex + rankDelta > 7 || RankIndex + rankDelta < 0 || FileIndex + fileDelta < 0)
		{
		cout << "off the board" << endl;
		return false;
		}

		else if (fileDelta != 0 && rankDelta != 0) {
		cout << "non linear attack" << endl;
		return false;
		}

		else if (Board::board[destFile][destRank].isOccupied == false)
		{
			cout << "square not occupied" << endl;
			return false;
		}

		else if (Board::board[destFile][destRank].Occupiere-> Colour == this->Colour)
		{
			cout << "cannot capture piece of same colour" << endl;
			return false;
		}



		else if (rankDelta > 0 && CheckUp() == true) {
			return true;
		}

		else if (CheckDown() == true && rankDelta < 0) {
			return true;
		}

		else if (CheckRight() == true && fileDelta > 0) {
			return true;
		}

		else if (CheckLeft() == true && fileDelta < 0) {
			return true;
		}

		else
		{
			cout << "collision" << endl;
			return false;
		}

		return true;
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

	void Piece::TryMove(int f, int r) {

	}


