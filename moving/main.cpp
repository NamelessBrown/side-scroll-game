// SFML_template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Game.h"

int main()
{
	sf::RenderWindow win(sf::VideoMode(1000, 600), "Side scroll", sf::Style::Close | sf::Style::Titlebar);

	Game game(win);
	game.Run();
}
