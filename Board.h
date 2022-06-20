#pragma once

#include"Square.h"
#include"Piece.h"
#include<iostream>
#include<tuple>

using namespace std;

class Board {
public:
	 static Square board[8][8];
	 Board();
	 static void PrintGamestate();
	 static void Play();

	 static string To_Coordinate(int fileIndex, int rankIndex);
	 static tuple<int, int> To_indexs(string coordinate);
};

