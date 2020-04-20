#include "Game.h"

Game::Game(sf::RenderWindow& window)
	:m_window(window), m_event(sf::Event())
{
}

void Game::Run()
{
	while (m_window.isOpen())
	{
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

void Game::Update()
{
	PollEvent();
}

void Game::Render()
{
	m_window.clear();

	m_window.display();
}
