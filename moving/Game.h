#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

class Game
{
public:
	Game(sf::RenderWindow& window);

	void Run();
private:
	sf::RenderWindow& m_window;
	sf::Event m_event;
	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;
	sf::Clock m_clock;

	float m_deltatime;
	double m_backgroundScroll;
	double m_backgroundScrollSpeed;

	Player m_player;

	void PollEvent();
	void ChangeBackground();
	void Update();
	void Render();
};

