#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& window)
	:m_window(window), m_event(sf::Event()), m_deltatime(60.f), m_backgroundScrollSpeed(.5f), m_backgroundScroll(0), m_enemiesSpawner(1)
{
	m_backgroundTexture.loadFromFile("Textures/gameBack.jpg");
	m_enemyTexture.loadFromFile("Textures/zombies.png");
	m_backgroundTexture.setSmooth(true);

	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setPosition(0.f, 0.f);

	for (int i = 0; i < m_enemiesSpawner; i++)
	{
		m_enemies.emplace_back(new Enemy(m_enemyTexture));
	}
}

Game::~Game()
{
	for (auto& e : m_enemies)
	{
		e.reset();
	}

	m_enemies.clear();
}

void Game::Run()
{
	while (m_window.isOpen())
	{
		m_deltatime = m_clock.restart().asSeconds() * 60.f;
		Update();
		Render();
	}
}

void Game::PollEvent()
{
	while (m_window.pollEvent(m_event))
	{
		switch (m_event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		}
	}
}

void Game::ChangeBackground()
{
	m_backgroundScroll = std::fmod((m_backgroundScroll + m_backgroundScrollSpeed * m_deltatime), 150);
	m_backgroundSprite.setPosition((float)-m_backgroundScroll, 0.f);
}

void Game::Update()
{
	PollEvent();
	ChangeBackground();
	m_player.Update(m_deltatime);

	Collision();

	for (unsigned x = 0; x < m_enemies.size(); x++)
	{
		m_enemies[x]->Update(m_deltatime);
	}
}

void Game::Collision()
{
	for (unsigned i = 0; i < m_enemies.size(); i++)
	{
		if (m_player.GetPlayer().getGlobalBounds().intersects(m_enemies[i]->GetEnemy().getGlobalBounds())) //bullets hit the enemy
		{
			m_enemies[i].reset();
			m_enemies.erase(m_enemies.begin() + i);
			m_enemies.emplace_back(new Enemy(m_enemyTexture));
		}
	}
}

void Game::Render()
{
	m_window.clear();

	m_window.draw(m_backgroundSprite);
	m_player.Render(m_window);

	for (unsigned x = 0; x < m_enemies.size(); x++)
	{
		m_enemies[x]->Render(m_window);
	}

	m_window.display();
}
