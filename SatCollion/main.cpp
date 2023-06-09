#include "Game.h"

int main()
{

    Game game;

	while (game.running())
	{

		game.dt = game.clock.restart().asSeconds();

		game.update();

		game.render();

	}

    return 0;
}
