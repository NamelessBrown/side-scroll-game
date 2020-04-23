#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"

class Game
{
public:
	Game(sf::RenderWindow& window);

	void Run();
private:
	void PollEvent();
	void ChangeBackground();
	void Update();
	void Render();
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
	std::vector<std::unique_ptr<Enemy>> m_enemies;
};

