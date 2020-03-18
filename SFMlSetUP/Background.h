#pragma once
#include "SFML\Graphics.hpp"	
#include <iostream>
using namespace std;
using namespace sf;
//These are all included to alllow me to acess the differnt libraries, and header files.
class Background
{
public:


	Background(float posX, float posY);//The floating point sets the postion for the y axies and the axies off the background.
	void Draw(sf::RenderWindow &window);//This void function draws the, texture.
	
	sf::Texture texture;
	~Background();
private:
	sf::RectangleShape background;//Then in the private class we draw the rectangle shape for the background.

};

