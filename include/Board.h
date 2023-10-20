#pragma once

#include"Square.h"
#include"Piece.h"
#include<tuple>
#include"FrontEnd.h"

using namespace std;

class Board {
public:
	 Board(int xSize, int ySize);
	 static Square* board[8][8];
	 static void PrintGamestate();
	 static void Play(Piece* selectedPiece, Square* destSquare);

	 static string To_Coordinate(int fileIndex, int rankIndex);
	 static tuple<int, int> To_indexs(string coordinate);

	 static Square* GetSquare(int file, int rank);

	 static void DrawBoard();

	 static void SetTurn();
	 static void Turn();
	 static string GetTurn() { return turn; }
private:
	static void SetSquare(int file, int rank, Square& square);
	static FrontEnd* frontEnd;
	static Square* ClickSquare(sf::Vector2f mousePostion);
	static string turn;
};

