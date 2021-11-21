#include<iostream>
#include<string>
#include<tuple>
#include<vector>
#include"Board.h"
#include"Piece.h"
#include"Square.h"
#include"White_Pawn.h"

using namespace std;

int main(){
	Board::Board();
	White_Pawn p(0,1);
	p.Move2();
	p.Move2();
	p.Move2();
	p.Move2();

	Board::PrintGamestate();
	//Board::board[1][1] = a;
	//Piece c = b.board[1][1];
	return 0;
}