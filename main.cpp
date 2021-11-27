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
#include"Bishop.h"
#include"King.h"
#include"Rook.h"
#include"Knight.h"

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
	Rook r(0, 0, "White");
	Knight kn(1, 0, "White");
	Bishop b0(2, 0, "White");
	Queen q(3, 0, "White");
	King k(4, 0, "White");
	Knight kn1(6, 0, "White");
	Bishop b1(5, 0, "White");
	Rook r1(7, 0, "White");

	Black_Pawn A(0, 6);
	Black_Pawn B(1, 6);
	Black_Pawn C(2, 6);
	Black_Pawn D(3, 6);
	Black_Pawn E(4, 6);
	Black_Pawn F(5, 6);
	Black_Pawn G(6, 6);
	Black_Pawn H(7, 6);
	Rook R(0, 7, "Black");
	Knight Kn(1, 7, "Black");
	Bishop B0(2, 7, "Black");
	Queen Q(3, 7, "Black");
	King K(4, 7, "Black");
	Knight Kn1(6, 7, "Black");
	Bishop B1(5, 7, "Black");
	Rook R1(7, 7, "Black");



	//a.Move2();
	//B.AttackLeft();
	//Piece::To_indexs()
	//Q.QueenDiagAttack(1, 1);
	//Q.QueenMove(, 2);
	//a.Move2();
	//kn.KnightMove(2, 2);
	
	Board::PrintGamestate();
	Board::MakeMove();


	//Board::board[1][1] = a;
	//Piece c = b.board[1][1];
	return 0;
}