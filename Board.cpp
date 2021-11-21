#include"Board.h"

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

		for (int file = 0; file < 8; file++) {
			Square square = board[file][rank];
			square.isOccupied ? cout << square.Occupiere->Symbol << "," : cout << " " << ",";
			
		}
		cout << endl;
	}
}