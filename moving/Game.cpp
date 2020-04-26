#include "Game.h"

Game::Game(sf::RenderWindow& window)
	:m_window(window), m_event(sf::Event()), m_deltatime(60.f), m_backgroundScrollSpeed(.5f), m_backgroundScroll(0), m_enemiesSpawner(1)
{

	m_backgroundSprite.setTexture(m_resourceHolder.getTexture("Textures/gameBack.jpg"));
	m_backgroundSprite.setPosition(0.f, 0.f);

	m_text.setFont(m_resourceHolder.getFont("Font/legalv2.ttf"));

	m_sound.setBuffer(m_resourceHolder.getSound("Sound/attack.wav"));

	m_player = Player(m_resourceHolder.getTexture("Textures/playerSheet.png"));

	for (int i = 0; i < m_enemiesSpawner; i++)
	{
		m_enemies.emplace_back(new Enemy(m_resourceHolder.getTexture("Textures/zombies.png")));
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

void Game::SpawnEnemy()
{
	if (m_enemies.empty())
	{
		m_enemies.emplace_back(new Enemy(m_resourceHolder.getTexture("Textures/zombies.png")));
	}
}

void Game::Collision()
{
	for (auto iter = m_enemies.begin(); iter != m_enemies.end();)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) && Collision::AxisAlignedBoundingBox(m_player.GetPlayer(), iter->get()->GetEnemy()))
		{
			iter = m_enemies.erase(iter);

			if (m_sound.getStatus() == sf::Sound::Status::Stopped)
			{
				m_sound.play();
			}
		}
		else if (iter->get()->GetEnemy().getPosition().x < 1.f)
		{
			m_player.LostHp(iter->get()->GetAttackDamage());
			iter = m_enemies.erase(iter);
		}
		else
		{
			iter->get()->Update(m_deltatime);
			iter++;
		}
	}
}

void Game::Update()
{
	std::stringstream ss;
	ss << "Health: " << m_player.GetHealth() << '\n';
	m_text.setString(ss.str());

	SpawnEnemy();
	PollEvent();
	ChangeBackground();
	m_player.Update(m_deltatime);
	Collision();
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

	m_window.draw(m_text);

	m_window.display();
}
