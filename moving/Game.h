#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <sstream>
#include "Player.h"
#include "Enemy.h"
#include "ResourceHolder.h"
#include "Collision.h"

enum class GameState
{
	title, playing, paused, gameOver
};

class Game
{
public:
	Game(sf::RenderWindow& window);
	~Game();

	void Run();
private:
	void PollEvent();
	void ChangeBackground();
	void SpawnEnemy();
	void HandleStates();
	void Collision();
	void Update();
	void Render();
private:
	ResourceHolder m_resourceHolder;

	sf::RenderWindow& m_window;
	sf::Event m_event;
	sf::Sprite m_backgroundSprite;
	sf::Clock m_clock;
	sf::Text m_text;
	sf::Sound m_sound;
	sf::Music m_music;

	float m_deltatime;
	double m_backgroundScroll;
	double m_backgroundScrollSpeed;
	int m_enemiesSpawner;
	bool m_gameOver;

	Player m_player;
	std::vector<std::unique_ptr<Enemy>> m_enemies;
	GameState m_state;
};

