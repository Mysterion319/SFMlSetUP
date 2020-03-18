#pragma once

#include <SFML/Graphics.hpp>
#include "Ship.h"
#include "Asteroids.h"
#include "Background.h"
#include "BlackHole.h"

class Game
{
public:
	Game();
	~Game();
	void ShipLives();//Void to load the Hud for my game.
	void Loop();

private:
	sf::RenderWindow* window;//Loads the window.
	Ship* ship;
	BlackHole* blackHole;
	BlackHole* blackHole2;
	Background* background;//loads the background class for the background header.
	Asteroids* asteroids;
	Asteroids* asteroids2;
	int Lives;//The integer to loads my set lives from the game.cpp.
	

};