#include "Game.h"

Game::Game(sf::RenderWindow& window)
	:m_window(window), m_event(sf::Event()), m_deltatime(60.f), m_backgroundScrollSpeed(.5f), m_backgroundScroll(0)
{
	m_backgroundTexture.loadFromFile("Textures/gameBack.jpg");
	m_backgroundTexture.setSmooth(true);

	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setPosition(0.f, 0.f);
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
	m_enemies.Update(m_deltatime);
}

void Game::Render()
{
	m_window.clear();

	m_window.draw(m_backgroundSprite);
	m_player.Render(m_window);
	m_enemies.Render(m_window);

	m_window.display();
}
