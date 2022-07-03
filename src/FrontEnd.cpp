#include "FrontEnd.h"

FrontEnd::FrontEnd(int xSize, int ySize)
{
    XSize = xSize;
    YSize = ySize;
}

sf::RenderWindow* FrontEnd::GetWindow()
{
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(XSize, YSize), "Chess");
    return window;
}