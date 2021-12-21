#include"Board.h"
#include"Queen.h"
#include"Rook.h"
#include"Bishop.h"
#include"Black_Pawn.h"
#include"King.h"
#include"Knight.h"
#include"White_Pawn.h"

using namespace std;

Square Board::board[8][8];
Board::Board() {
	for (int file = 0; file < 8; file++) {
		for (int rank = 0; rank < 8; rank++) {
			board[file][rank].FileIndex = file;
			board[file][rank].RankIndex = rank;
			board[file][rank].coordinate = Piece::To_Coordinate(file, rank);
		}
	}
}

void Board::PrintGamestate() {
		
	for (int rank = 7; rank > -1; rank--) {
		
		cout << rank + 1<< "|";

		for (int file = 0; file < 8; file++) {
			
			Square square = board[file][rank];
			square.isOccupied ? cout << square.Occupiere->Symbol << "|" : cout << " " << "|";
			
		}
		cout << endl;
	}
	cout << " |a|b|c|d|e|f|g|h|" << endl;
}



void Board::Play() {
	
	string coor;
	while (coor != "q")
	{
		cout << "select piece" << endl;
		cin >> coor;
		auto  indexes = Piece::To_indexs(coor);
		Piece* piece = Board::board[get<0>(indexes)][get<1>(indexes)].Occupiere;
		cout << "enter move" << endl;
		cin >> coor;
		indexes = Piece::To_indexs(coor);

		if (piece->Type == "Queen") {
			piece->TryMove(get<0>(indexes), get<1>(indexes));
		}
		else if (piece->Type == "Rook") {
			piece->TryMove(get<0>(indexes), get<1>(indexes));
		}
		else if (piece->Type == "Bishop") {
			piece->TryMove(get<0>(indexes), get<1>(indexes));
		}
		else if (piece->Type == "King") {
			piece->TryMove(get<0>(indexes), get<1>(indexes));
		}
		else if (piece->Type == "Knight") {
			piece->TryMove(get<0>(indexes), get<1>(indexes));
		}
		else if (piece->Type == "White_Pawn") {
			piece->TryMove(get<0>(indexes), get<1>(indexes));
		}
		else if (piece->Type == "Black_Pawn") {
			piece->TryMove(get<0>(indexes), get<1>(indexes));
		}
		//else if(piece->Type == "Rook")

		PrintGamestate();
	}
}