#include<iostream>
#include<string>
#include<tuple>
#include<vector>
#include"Board.h"
#include"Piece.h"
#include"Square.h"
#include"Pawn.h"
#include"Queen.h"
#include"Bishop.h"
#include"King.h"
#include"Rook.h"
#include"Knight.h"

using namespace std;

int main(){
	Board::Board();
	Pawn a(0, 1, "white");
	Pawn b(1, 1, "white");
	Pawn c(2, 1, "white");
	Pawn d(3, 1, "white");
	Pawn e(4, 1, "white");
	Pawn f(5, 1, "white");
	Pawn g(6, 1, "white");
	Pawn h(7, 1, "white");
	Rook r(0, 0, "White");
	Knight kn(1, 0, "White");
	Bishop b0(2, 0, "White");
	Queen q(3, 0, "White");
	King k(4, 0, "White");
	Knight kn1(6, 0, "White");
	Bishop b1(5, 0, "White");
	Rook r1(7, 0, "White");

	Pawn A(0, 6, "black");
	Pawn B(1, 6, "black");
	Pawn C(2, 6, "black");
	Pawn D(3, 6, "black");
	Pawn E(4, 6, "black");
	Pawn F(5, 6, "black");
	Pawn G(6, 6, "black");
	Pawn H(7, 6, "black");
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
	//Q.QueenAttack(1, 1);
	//Q.QueenMove(, 2);
	//a.Move2();
	//kn.KnightMove(2, 2);
	
	Board::PrintGamestate();
	Board::Play();


	//Board::board[1][1] = a;
	//Piece c = b.board[1][1];
	return 0;
}