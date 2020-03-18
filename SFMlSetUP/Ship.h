#pragma once

#include <SFML/Graphics.hpp>

class Ship
{

private:
	sf::RectangleShape *ship;//This draws the recntagle shape used for the frog.
	sf::Sprite sprite;//This class creates the sprite.
	sf::Texture texture;//This is the texture, used for adding a image to the frog.
	float originalPosX, originalPosY;
public:
	Ship(sf::Vector2u size, float posX, float posY);
	void Draw(sf::RenderWindow& window);//Draws the frog to the window.
	float rotate;
	//void lookAtMouse();
	void Move(sf::Event event);//Sets the movemnt of the frog.
	sf::RectangleShape* GetShape();//This draws the recntagle shape used for the frog.


	~Ship();
};
