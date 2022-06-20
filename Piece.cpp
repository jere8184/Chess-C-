#include "Piece.h"
#include "Queen.h"

using namespace std;

	Piece::Piece(int fileIndex, int rankIndex, string colour)
		: FileIndex(fileIndex), RankIndex(rankIndex), Colour(colour), Coordinate(To_Coordinate(FileIndex, RankIndex))
	{
		SetPosition(&Board::board[GetFile()][GetRank()]);
		this->GetPosition()->SetOccupation(true);
		this->GetPosition()->SetOccupier(this);
	}

	void Piece::Move(int destFile, int destRank) {
		this->SetPosition(&Board::board[destFile][destRank]);
		this->Moved = true;
	}

	void Piece::Captured() {
		this->GetPosition()->SetOccupier(nullptr);
		this->GetPosition()->SetOccupation(false);
		this->IsCaptured = true;
	}

	void Piece::Attack(int destFile, int destRank) {
		Board::board[destFile][destRank].GetOccupier()->Captured();
		Move(destFile, destRank);
	}

	//checks move is legal and the makes the move if it is
	void Piece::TryMove(int destFile, int destRank) {
		if (ValidateMove(destFile, destRank) && StandardChecks(destFile, destRank) && Search(destFile, destRank))
		{
			Board::board[destFile][destRank].IsOccupied() ? Attack(destFile, destRank) : Move(destFile, destRank);
		}
	}

	//searches squares INBETWEEN starting postion and destination postion, returns true if all squares unoccupied, or false if one or more of the squares is occupied
	bool Piece::Search(int destFile, int destRank) {

		int fileDelta = GetFileDelta(destFile);
		int rankDelta = GetRankDelta(destRank);
		int fileDirection = (fileDelta > 0) - (fileDelta < 0);
		int rankDirection = (rankDelta > 0) - (rankDelta < 0); //will be 1 or -1 or 0

		for (int i = FileIndex + fileDirection; i + fileDirection != destFile; i += fileDirection) {
			if (Board::board[i][RankIndex].IsOccupied() == true) {
				return false;
			}
		}

		for (int i = RankIndex + rankDirection; i * rankDirection != destRank; i += rankDirection) {
			if (Board::board[FileIndex][i].IsOccupied() == true) {
				return false;
			}
		}

		return true;
	}

	bool Piece::StandardChecks(int destFile, int destRank)
	{
		int fileDelta = GetFileDelta(destFile);
		int rankDelta = GetRankDelta(destRank);

		if(fileDelta == 0 && rankDelta == 0)
		{
			cout << "non move\n";
			return false;
		}

		if(destFile > 7 || destFile < 0)
		{
			cout << "file out of bounds\n";
			return false;
		}

		if (destRank > 7 || destRank < 0)
		{
			cout << "rank out of bounds\n";
			return false;
		}

		else
		{
			return true;
		}

	}

	bool Piece::IsDiaganolMove(int fileDelta, int rankDelta)
	{
		if(abs(fileDelta) != abs(rankDelta))
		{
			//cout << "non diagonal move \n";
			return false;
		}
		return true;
	}

	bool Piece::IsLinearMove(int fileDelta, int rankDelta)
	{
		if ((fileDelta != 0 && rankDelta != 0) && (abs(fileDelta) != abs(rankDelta)))
		{
			//cout << "non linear move" << endl;
			return false;
		}

		return true;
	}

	bool Piece::IsStraightMove(int fileDelta, int rankDelta)
	{
		if ((fileDelta != 0 && rankDelta != 0))
		{
			//cout << "non straight move" << endl;
			return false;
		}

		return true;
	}

	void Piece::SetPosition(Square* iPositon)
	{
		if(Position != nullptr)
		{
			Position->SetOccupier(nullptr);
			Position->SetOccupation(false);
		}
		Position = iPositon;
		this->Coordinate = Position->GetCoordinate();
		Position->SetOccupier(this);
		Position->SetOccupation(true);
	}




