#pragma once

#include"Square.h"
#include"Piece.h"
#include<iostream>

using namespace std;

class Board {
public:
	 static Square board[8][8];
	 Board();
	 static void PrintGamestate();
};