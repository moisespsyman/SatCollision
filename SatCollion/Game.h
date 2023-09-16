#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <math.h>


#include "Polygon.h"

#include "Player1.h"
#include "Player2.h"
#include "SatCollision.h"

using namespace sf;

class Game
{
private:

	RenderWindow* window;
	VideoMode videomode;
	const char* title;

	Event event;

	Player1 player1;
	Player2 player2;

	void InitVariables();
	void InitWindow();

public:

	Game();
	virtual ~Game();

	// Accessors
	const bool running() const;

	Clock clock;
	float dt;
	
	//Modifiers
	void pollEvents();

	void update();
	void render();

};

