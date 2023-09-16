#include "Game.h"

void Game::InitVariables()
{

    this->window = nullptr;

}

void Game::InitWindow()
{
    this->videomode.width = 1280;
    this->videomode.height = 720;
    this->title = "SAT";
    this->window = new RenderWindow(videomode, title, Style::Titlebar | Style::Close);


}

Game::Game()
{
    this->InitVariables();
    this->InitWindow();
}

Game::~Game()
{
    delete this->window;
}

const bool Game::running() const
{
    return window->isOpen();
}

void Game::pollEvents()
{
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
        case Event::Closed:
            window->close();
            break;
        }
    }
}

void Game::update()
{
    this->pollEvents();

    player1.UpdatePlayer(dt);
    player1.update();

    player2.UpdatePlayer(dt);

    if (Sat_Overlap_STATIC(player1, player2))
    {
        player1.fillColor = Color(255, 0, 0, 255);
    }
    else
    {
        player1.fillColor = Color(255, 0, 255, 255);
    }

    player2.update();

}

void Game::render()
{
    window->clear(Color::Black);

    player1.render(this->window);

    player2.render(this->window);

    window->display();
}
