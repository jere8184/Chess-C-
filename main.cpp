#include<iostream>
#include<string>
#include<tuple>
#include<vector>
#include"Board.h"
#include"Piece.h"
#include"Square.h"
#include"White_Pawn.h"
#include"Black_Pawn.h"
#include"Queen.h"

using namespace std;

int main(){
	Board::Board();
	White_Pawn a(0, 1);
	White_Pawn b(1, 1);
	White_Pawn c(2, 1);
	White_Pawn d(3, 1);
	White_Pawn e(4, 1);
	White_Pawn f(5, 1);
	White_Pawn g(6, 1);
	White_Pawn h(7, 1);
	Queen Q(0, 0, "White");

	Black_Pawn A(0, 6);
	Black_Pawn B(1, 6);
	Black_Pawn C(2, 6);
	Black_Pawn D(3, 6);
	Black_Pawn E(4, 6);
	Black_Pawn F(5, 6);
	Black_Pawn G(6, 6);
	Black_Pawn H(7, 6);



	//a.Move2();
	//B.AttackLeft();
	//Piece::To_indexs()
	Q.QueenDiagAttack(1, 1);
	//Q.QueenMove(, 2);
	a.Move2();
	
	Board::PrintGamestate();


	//Board::board[1][1] = a;
	//Piece c = b.board[1][1];
	return 0;
}