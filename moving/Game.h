#pragma once

#include <SFML/Graphics.hpp>

class Game
{
public:
	Game(sf::RenderWindow& window);

	void Run();
private:
	sf::RenderWindow& m_window;
	sf::Event m_event;


	void PollEvent();
	void Update();
	void Render();
};

