#include "Background.h"
#include <iostream>

//These are all included to alllow me to acess the differnt libraries, and header files.




Background::Background(float posX, float posY)//The floatingn point sets the postion for the y axies and the axies off the background.
{
	background.setSize(sf::Vector2f(800, 600));//I set the size off the background the same size off the window, so it would fit.
	background.setPosition(0, 0);//The postion off  the background was set to 0.0 the reason why was a backlgorund doesn't need a set postion as it will cover the whole screen
	if (!texture.loadFromFile("../assets/space.jpg"))//This if statement loads the background PNG file from the SFML folder.
	{
		
	}

	const sf::Texture* pTexture = &texture;
	background.setTexture(pTexture);

}




void Background::Draw(sf::RenderWindow& window)
{
	window.draw(background);//This draws the background to the window.
}


Background::~Background()
{
}

