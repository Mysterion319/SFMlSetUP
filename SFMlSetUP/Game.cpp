#include "Game.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include <sstream>
#include <string>


Game::Game()
{
	
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML Starter Template");
	ship = new Ship(window->getSize(), 100.f, 100.f);




	//blackhole

	blackHole = new BlackHole(700, window->getSize().y - 580);
	blackHole2 = new BlackHole(200, window->getSize().y - 200);





	asteroids = new Asteroids(window->getSize(), 0, window->getSize().y / 2);

	background = new Background(0, window->getSize().y);//This function links to the backgorund header and loads the set postion i chose and gets the size for the window.
	Lives = 3;//This function works out how many lifes are left the display, header will show the score and lifes off the player.
}
 

Game::~Game()
{
}

void Game::Loop()
{
	

	

	
	while (window->isOpen())
	{
		// handle events
		sf::Event event;

		while (window->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:

				ship->Move(event);

				break;

			default:
				break;
			}
		}

		

		// update
		asteroids->Move(window->getSize());
		//ship->lookAtMouse();

		//collisons 
		if (ship->GetShape()->getGlobalBounds().intersects(asteroids->GetShape().getGlobalBounds()))
		{
			Lives--;
			ship = new Ship(window->getSize(), 100, 100);
			if (Lives == 0)//This is where I have set the lives to three.
			{
				window->close();
			}
		}
	
		if (ship->GetShape()->getGlobalBounds().intersects(blackHole->GetShape().getGlobalBounds()))
		{
			Lives--;
			ship = new Ship(window->getSize(), 100, 100);
			if (Lives == 0)//This is where I have set the lives to three.
			{
				window->close();
			}
		}
		if (ship->GetShape()->getGlobalBounds().intersects(blackHole2->GetShape().getGlobalBounds()))
		{
			Lives--;
			ship = new Ship(window->getSize(), 100, 100);
			if (Lives == 0)//This is where I have set the lives to three.
			{
				window->close();
			}
		}
			   

		window->clear();

		// draw SFML content
		background->Draw(*window);
		blackHole->Draw(*window);
		blackHole2->Draw(*window);
		ShipLives();
		ship->Draw(*window);
		
		asteroids->Draw(*window);
	
		window->display();
	}
}
void Game::ShipLives()
{
	Font font;//sets the font
	Text text;//sets the text
	Text ShipLives;//writes what it says in frog lives.

	if (!font.loadFromFile("font/arial.ttf"))
	{

	}

	ShipLives.setFont(font);//sets the font.
	ShipLives.setCharacterSize(40);//sets the amount of characters you are allowed to use.
	ShipLives.setFillColor(sf::Color::White);//sets the fill colour
	std::stringstream ss;
	ss << "Ship Lives:" << Lives;//Prints frog lives to the screen.
	ShipLives.setString(ss.str());
	window->draw(ShipLives);//string loads the amount off lives.

}
