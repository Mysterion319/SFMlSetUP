#include "Asteroids.h"




Asteroids::Asteroids(sf::Vector2u size, float posX, float posY)
{
	asteroids.setSize(sf::Vector2f(120, 60));
	asteroids.setFillColor(sf::Color::Red);
	asteroids.setPosition(sf::Vector2f(posX, posY));
	
	originalPosX = posX;
	originalPosY = posY;
}


Asteroids::~Asteroids()
{
}
void Asteroids::Draw(sf::RenderWindow& window)
{
	window.draw(asteroids);
}

void Asteroids::Move(sf::Vector2u size)
{
	asteroids.move(0.2, 0);

	if (asteroids.getPosition().x > size.x)
	{
		asteroids.setPosition(sf::Vector2f(0 - asteroids.getSize().x, originalPosY));
	}
}

sf::RectangleShape Asteroids::GetShape()
{
	return asteroids;
}