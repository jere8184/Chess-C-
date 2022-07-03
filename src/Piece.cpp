#include "Piece.h"
using namespace std;

	Piece::Piece(int fileIndex, int rankIndex, string colour)
		: FileIndex(fileIndex), RankIndex(rankIndex), Colour(colour)
	{
		SetPosition(Board::GetSquare(FileIndex, RankIndex));
		GetPosition()->SetOccupation(true);
		GetPosition()->SetOccupier(this);
		Coordinate = GetPosition()->GetCoordinate();
	}

	void Piece::Move(int destFile, int destRank) {
		this->SetPosition(Board::GetSquare(destFile, destRank));
		this->Moved = true;
	}

	void Piece::Captured() {
		GetPosition()->SetOccupier(nullptr);
		GetPosition()->SetOccupation(false);
		IsCaptured = true;
	}

	void Piece::Attack(int destFile, int destRank) {
		Board::GetSquare(destFile, destRank)->GetOccupier()->Captured();
		Move(destFile, destRank);
	}

	//checks move is legal and the makes the move if it is
	void Piece::TryMove(int destFile, int destRank) {
		if (ValidateMove(destFile, destRank) && StandardChecks(destFile, destRank) && Search(destFile, destRank))
		{
			Board::GetSquare(destFile, destRank)->IsOccupied() ? Attack(destFile, destRank) : Move(destFile, destRank);
			Board::Turn();
		}
	}

	//searches squares INBETWEEN starting postion and destination postion, returns true if all squares unoccupied, or false if one or more of the squares is occupied
	bool Piece::Search(int destFile, int destRank) {

		if (Type == "Knight")
		{
			return true;
		}

		int fileDelta = GetFileDelta(destFile);
		int rankDelta = GetRankDelta(destRank);
		int fileDirection = (fileDelta > 0) - (fileDelta < 0);
		int rankDirection = (rankDelta > 0) - (rankDelta < 0); //will be 1 or -1 or 0

		
		int file = FileIndex + fileDirection;
		int rank = RankIndex + rankDirection;
		while(Board::GetSquare(destFile, destRank) != Board::GetSquare(file, rank))
		{
			if(Board::GetSquare(file, rank)->IsOccupied())
			{
				cout << "blocked" << endl;
				return false;
			}
			file += fileDirection;
			rank += rankDirection;
		}
		
		/*for (int i = FileIndex + fileDirection; i * fileDirection != destFile; i += fileDirection) {
			if (Board::GetSquare(destFile, destRank)->IsOccupied()) {
				return false;
			}
		}

		for (int i = RankIndex + rankDirection; i * rankDirection != destRank; i += rankDirection) {
			if (Board::GetSquare(destFile, destRank)->IsOccupied()) {
				return false;
			}
		}*/

		return true;
	}

	bool Piece::StandardChecks(int destFile, int destRank)
	{
		int fileDelta = GetFileDelta(destFile);
		int rankDelta = GetRankDelta(destRank);

		if(GetColour() != Board::GetTurn())
		{
			cout << "not your turn\n";
			return false;
		}

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

		if (Board::GetSquare(destFile, destRank)->IsOccupied() && Board::GetSquare(destFile, destRank)->GetOccupier()->GetColour() == GetColour())
		{
			cout << "dest square occupied by same colour\n";
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
			return false;
		}
		return true;
	}

	bool Piece::IsLinearMove(int fileDelta, int rankDelta)
	{
		if ((fileDelta != 0 && rankDelta != 0) && (abs(fileDelta) != abs(rankDelta)))
		{
			return false;
		}

		return true;
	}

	bool Piece::IsStraightMove(int fileDelta, int rankDelta)
	{
		if ((fileDelta != 0 && rankDelta != 0))
		{
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
		SetFile(Position->GetFile());
		SetRank(Position->GetRank());
		Position->SetOccupier(this);
		Position->SetOccupation(true);
	}

	void Piece::SetTexture(string name) 
	{
		string path = "../deps/SPRITES/" + name;
		Texture.loadFromFile(path);
	}




