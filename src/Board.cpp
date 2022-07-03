#include"Board.h"
#include"Queen.h"
#include"Rook.h"
#include"Bishop.h"
#include"Pawn.h"
#include"King.h"
#include"Knight.h"


using namespace std;

Board::Board(int xSize, int ySize) 
{
	//instantiate squares
	for (int file = 0; file < 8; file++) {
		for (int rank = 0; rank < 8; rank++) {
			Square* square = new Square(file, rank);
			SetSquare(file, rank, *square);
		}
	}
	turn = "White";
	//instatiate FE
	FrontEnd fe(xSize, ySize);
	frontEnd = new FrontEnd(xSize, ySize);
}

Square* Board::board[8][8];
FrontEnd* Board::frontEnd;
string Board::turn;

void Board::PrintGamestate() {
		
	for (int rank = 7; rank > -1; rank--) {
		
		cout << rank + 1<< "|";

		for (int file = 0; file < 8; file++) {
			
			Square square = *board[file][rank];
			square.IsOccupied() ? cout << square.GetOccupier()->GetSymbol() << "|" : cout << " " << "|";
			
		}
		cout << endl;
	}
	cout << " |a|b|c|d|e|f|g|h|" << endl;
}

void Board::Play(Piece* selectedPiece, Square* destSquare)
{
	
	//string input;
	//while (input != "q")
	//{
	//cout << "select piece" << endl;
	//cin >> input;
	//tuple<int,int> indexes = Board::To_indexs(input);
	//Piece* selectedPiece;
	//if(GetSquare(get<0>(indexes), get<1>(indexes))->IsOccupied())
	//{
	//	selectedPiece = board[get<0>(indexes)][get<1>(indexes)]->GetOccupier();
	//}
	//else
	//{
	//	return;
	//}
	//cout << "enter move" << endl;
	//cin >> input;
	//indexes = Board::To_indexs(input);
	selectedPiece->TryMove(destSquare->GetFile(), destSquare->GetRank());
	PrintGamestate();
	//}
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


Square* Board::GetSquare(int file, int rank)
{
	Square* square = board[file][rank];
	return square;
}

void Board::SetSquare(int file, int rank, Square& square)
{
	board[file][rank] = &square;
}


void Board::DrawBoard()
{
	Piece* selcetedPiece = nullptr;
	Square* destSquare = nullptr;
	//set square spritesS
	float squareSpriteSize = frontEnd->XSize / 8;
	sf::RenderWindow* w = frontEnd->GetWindow();
	w->setFramerateLimit(10);
	while (w->isOpen())
	{
		//draw board
		for (auto& file : board)
		{
			for (Square* square : file)
			{
				square->SetSprite(squareSpriteSize);
				w->draw(*square->GetSprite());
				if(square->IsOccupied())
				{
					sf::Texture t = *square->GetOccupier()->GetTexture();
					sf::Sprite s(t);
					s.setPosition(square->GetSprite()->getPosition());
					w->draw(s);
				}
			}
		}

		sf::Event event;
		while (w->pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					w->close();
				case sf::Event::MouseButtonPressed:
					sf::Vector2i mPos = sf::Mouse::getPosition(*w);
					sf::Vector2f fMPos = w->mapPixelToCoords(mPos);
					Square* selctedSquare = ClickSquare(fMPos);
					if(selcetedPiece != nullptr)
					{
						destSquare = selctedSquare;
					}
					else if(selctedSquare->IsOccupied())
					{
						selcetedPiece = selctedSquare->GetOccupier();
					}
			}
		}
		w->display();
		if(selcetedPiece != nullptr && destSquare != nullptr)
		{
			Play(selcetedPiece, destSquare);
			selcetedPiece = nullptr;
			destSquare = nullptr;
		}
		w->clear();
	}
}

Square* Board::ClickSquare(sf::Vector2f mousePostion)
{
	for(auto& file : board)
	{
		for(Square* square : file)
		{
			if (square->GetSprite()->getGlobalBounds().contains(mousePostion))
			{
				cout << square->GetCoordinate() << endl;
				return square;
			}
		}
	}
}

void Board::Turn()
{
	if(turn == "White")
	{
		turn = "Black";
	}
	else
	{
		turn = "White";
	}
}

/*sf::Vector2i mPos = sf::Mouse::getPosition(*w);
for (auto& file : board)
{
	for (Square* square : file)
	{
		sf::Vector2f sPos = square->GetSprite()->getPosition();
		if (square->IsOccupied() && mPos.x > sPos.x && mPos.x < sPos.x + 100 && mPos.y > sPos.y && mPos.y < sPos.y + 100)
		{
			Square* selectedSquare = square;
		}
	}
}*/