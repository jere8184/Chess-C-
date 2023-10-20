#pragma once
#include <SFML/Graphics.hpp>
class FrontEnd
{
public:
	int XSize;
	int YSize;
	FrontEnd(int xSize, int ySize);
	sf::RenderWindow* GetWindow();
};