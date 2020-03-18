#include "Ship.h"
#include <iostream>
typedef sf::Vector2f Float2;

float Dot(Float2 v1, Float2 v2) // dot product 
{
	return (v1.x * v2.x) + (v1.y * v2.y);
}
Float2 Rotate(Float2 v, float angleRadians)
{
	return Float2(
		v.x * cos(angleRadians) - v.y * sin(angleRadians),
		v.x * sin(angleRadians) + v.y * cos(angleRadians)
	);
}




Ship::Ship(sf::Vector2u size, float posX, float posY)
{



	ship = new sf::RectangleShape();// adding in new assigns it to the heap.
	sf::Texture* backgroundTexture;  backgroundTexture = new sf::Texture(); 
	
	if (!backgroundTexture->loadFromFile("../assets/ship.png"))
	{

	}
	ship->setTexture(backgroundTexture);
	ship->setOrigin(sf::Vector2f(ship->getPosition().x + 40, size.y - ship->getSize().y + 40));//sets the orign of the ship. 
	ship->setSize(sf::Vector2f(80, 80));
	ship->setPosition(sf::Vector2f(posX, posY));
	ship->setTexture(backgroundTexture);
	ship->rotate(0.1f);

	originalPosX = posX;
	originalPosY = posY;
}	


Ship::~Ship()
{
}


void Ship::Draw(sf::RenderWindow& window)
{
	//sf::Vector2f curPos = ship->getPosition();
	//
	//
	//
	//
	//sf::Vector2f position = sf::Vector2f(100, 100);
	//sf::Vector2f GoalDistance = sf::Vector2f(position.x - curPos.x, position.y - curPos.y);
	//sf::Vector2f heading = sf::Vector2f(0, 80 - curPos.y);
	//sf::Vector2f NTP;
	//sf::Vector2f NH;

	//float mag1 = sqrt(pow(GoalDistance.x, 2) + pow(GoalDistance.y, 2));
	//float mag2 = sqrt(pow(heading.x, 2) + pow(heading.y, 2));
	//const float PI = 3.14159265;
	//NTP.x = GoalDistance.x / mag1; NTP.y = NTP.y / mag1;
	//NH.x = heading.x / mag2; NH.y = heading.y / mag2;
	//float dotproduct;

	//dotproduct = (GoalDistance.x * heading.x) + (GoalDistance.y * heading.y);//dot product
	/*if (curPos.x < position.x) {
		ship->setRotation(acos(dotproduct));

	}
	else
	{
		ship->setRotation(acos(dotproduct) * -1);
	}	*/

	window.draw(*ship);
}

void Ship::Move(sf::Event event)
{

	if (sf::Keyboard::Key::A == event.key.code)
	{
		 rotate = rotate + 10;
		//ship->move(-80, 0);
		ship->rotate(10.f);
		std::cout << rotate << std::endl;

	}
	else if (sf::Keyboard::Key::D == event.key.code)
	{
		ship->move(80, 0);
		
	}
	else if (sf::Keyboard::Key::W == event.key.code)
	{
		ship->move(0, -80);
	}
	else if (sf::Keyboard::Key::S == event.key.code)
	{
		ship->move(0, 80);
	}


	//collison 


	if (ship->getPosition().x > 360)
	{
		ship->setPosition(360, ship->getPosition().y);
	}
	if (ship->getPosition().x < -360)
	{
		ship->setPosition(-360, ship->getPosition().y);
	}
	if (ship->getPosition().y > 560)
	{
		ship->setPosition(ship->getPosition().x, 560);
	}
	if (ship->getPosition().y < 20)
	{
		ship->setPosition(ship->getPosition().x, 20);
	}



}

sf::RectangleShape *Ship::GetShape()
{
	return ship;
}