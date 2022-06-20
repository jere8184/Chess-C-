#include"Board.h"
#include"Queen.h"
#include"Rook.h"
#include"Bishop.h"
#include"Pawn.h"
#include"King.h"
#include"Knight.h"

using namespace std;

Square Board::board[8][8];
Board::Board() {
	for (int file = 0; file < 8; file++) {
		for (int rank = 0; rank < 8; rank++) {
			board[file][rank].SetRank(file);
			board[file][rank].SetFile(rank);
			board[file][rank].SetCooridnate(Piece::To_Coordinate(file, rank));
		}
	}
}

void Board::PrintGamestate() {
		
	for (int rank = 7; rank > -1; rank--) {
		
		cout << rank + 1<< "|";

		for (int file = 0; file < 8; file++) {
			
			Square square = board[file][rank];
			square.IsOccupied() ? cout << square.GetOccupier()->GetSymbol() << "|" : cout << " " << "|";
			
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
		Piece* piece = Board::board[get<0>(indexes)][get<1>(indexes)].GetOccupier();
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