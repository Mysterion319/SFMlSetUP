#pragma once

#include <SFML/Graphics.hpp>

class Asteroids
{
public:
	Asteroids(sf::Vector2u size, float posX, float posY);
	~Asteroids();

	void Draw(sf::RenderWindow& window);
	void Move(sf::Vector2u size);
	sf::RectangleShape GetShape();

private:
	sf::RectangleShape asteroids;

	float originalPosX, originalPosY;


};