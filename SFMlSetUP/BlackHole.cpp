#include "BlackHole.h"
#include <iostream>

//These are all included to alllow me to acess the differnt libraries, and header files.



BlackHole::BlackHole(float posX, float posY)
{

	blackHole.setSize(sf::Vector2f(80, 60));
	blackHole.setPosition(sf::Vector2f(posX, posY));

	if (!texture.loadFromFile("../assets/blackhole.png"))
	{

	}

	const sf::Texture* pTexture = &texture;
	blackHole.setTexture(pTexture);

}




	



BlackHole::~BlackHole()
{
}
void BlackHole::Draw(sf::RenderWindow& window)
{
	window.draw(blackHole);
}



sf::RectangleShape BlackHole::GetShape()
{
	return blackHole;
}




















