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
			board[file][rank].SetCooridnate(Board::To_Coordinate(file, rank));
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
	
	string input;
	while (input != "q")
	{
		cout << "select piece" << endl;
		cin >> input;
		tuple<int,int> indexes = Board::To_indexs(input);
		Piece* selectedPiece = board[get<0>(indexes)][get<1>(indexes)].GetOccupier();
		cout << "enter move" << endl;
		cin >> input;
		indexes = Board::To_indexs(input);
		selectedPiece->TryMove(get<0>(indexes), get<1>(indexes));
		PrintGamestate();
	}
}

string Board::To_Coordinate(int fileIndex, int rankIndex) {

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

tuple<int, int> Board::To_indexs(string coordinate) {

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