#pragma once
#include "SFML\Graphics.hpp"	
#include <iostream>


class BlackHole
{
public:
	BlackHole(float posX, float posY);
	float truckspeed = 10;
	void Draw(sf::RenderWindow& window);
		
	sf::RectangleShape GetShape();
	sf::Texture texture;
	   	~BlackHole();
private:
	sf::RectangleShape blackHole;
	float originalPosX, originalPosY;
};
