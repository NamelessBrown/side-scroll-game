#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "ResourceHolder.h"
#include "Collision.h"

class Game
{
public:
	Game(sf::RenderWindow& window);
	~Game();

	void Run();
private:
	void PollEvent();
	void ChangeBackground();
	void Update();
	void Render();
private:
	ResourceHolder m_resourceHolder;

	sf::RenderWindow& m_window;
	sf::Event m_event;
	sf::Sprite m_backgroundSprite;
	sf::Clock m_clock;

	float m_deltatime;
	double m_backgroundScroll;
	double m_backgroundScrollSpeed;
	int m_enemiesSpawner;

	Player m_player;
	std::vector<std::unique_ptr<Enemy>> m_enemies;
};

